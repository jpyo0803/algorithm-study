// 버스 갈아타기
// https://www.acmicpc.net/problem/2356

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, m, k;

vector<int> adj[5005];
int dist[5005];

struct Segment {
  int b, x1, y1, x2, y2;
  bool vert;

  Segment(int _b, int _x1, int _y1, int _x2, int _y2) 
    : b(_b), x1(_x1), y1(_y1), x2(_x2), y2(_y2) {
      if (x1 == x2) vert = false;
      else vert = true;
    }

  bool IsCross(const Segment& other) {
    if (vert == other.vert) {
      if (vert) {
        if (y1 != other.y1) return false;
        if (x2 < other.x1 || other.x2 < x1) return false;
      } else {
        if (x1 != other.x1) return false;
        if (y2 < other.y1 || other.y2 < y1) return false;
      }
    } else {
      if (vert) {
        if (other.x1 < x1 || x2 < other.x1) return false;
        if (y1 < other.y1 || other.y2 < y1) return false;
      } else {
        if (other.y1 < y1 || y2 < other.y1) return false;
        if (x1 < other.x1 || other.x2 < x1) return false;
      }
    }
    return true;
  }

  bool OnSegment(int x, int y) {
    if (vert) {
      if (y1 != y) return false;
      if (x < x1 || x2 < x) return false;
    } else {
      if (x1 != x) return false;
      if (y < y1 || y2 < y) return false;
    }
    return true;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n;
  cin >> k;

  vector<Segment> bv;
  for (int i = 0; i < k; ++i) {
    // x is row, y is col
    int b, x1, y1, x2, y2;
    cin >> b >> y1 >> x1 >> y2 >> x2;
    if (x1 == x2 && y1 > y2) swap(y1, y2);
    if (y1 == y2 && x1 > x2) swap(x1, x2);
    bv.emplace_back(b, x1, y1, x2, y2);
  }

  for (int i = 0; i < bv.size() - 1; ++i) {
    for (int j = i + 1; j < bv.size(); ++j) {
      if (bv[i].IsCross(bv[j])) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  int sx, sy, dx, dy;
  cin >> sy >> sx >> dy >> dx;
  vector<int> dst;

  queue<int> que;
  for (int i = 0; i < bv.size(); ++i) {
    if (bv[i].OnSegment(sx, sy)) {
      que.push(i);
      dist[i] = 1;
    } else {
      dist[i] = -1;
    }

    if (bv[i].OnSegment(dx, dy)) {
      dst.push_back(i);
    }
  }

  int ans = -1;
  while (que.size()) {
    int u = que.front();
    que.pop();

    for (auto t : dst) {
      if (t == u) {
        ans = dist[u];
        break;
      }
    }
    if (ans != -1) break;

    for (auto& v : adj[u]) {
      if (dist[v] != -1) continue;
      que.push(v);
      dist[v] = dist[u] + 1;
    }
  }

  cout << ans << "\n";

  return 0;
}
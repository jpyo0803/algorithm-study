// 로고
// https://www.acmicpc.net/problem/3108

#include <bits/stdc++.h>

using namespace std;

int n;

tuple<int, int, int, int> rects[1005];


bool IsOverlapSegment(int a1, int a2, int b1, int b2) {
  return !(a2 < b1 || b2 < a1);
}

bool IsOverlapRect(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
  int a_x1 = get<0>(a), a_y1 = get<1>(a), a_x2 = get<2>(a), a_y2 = get<3>(a);
  int b_x1 = get<0>(b), b_y1 = get<1>(b), b_x2 = get<2>(b), b_y2 = get<3>(b);

  return IsOverlapSegment(a_x1, a_x2, b_x1, b_x2) && IsOverlapSegment(a_y1, a_y2, b_y1, b_y2);
}

bool IsIncludedRect(const tuple<int, int, int, int>& a, const tuple<int, int, int, int>& b) {
  int a_x1 = get<0>(a), a_y1 = get<1>(a), a_x2 = get<2>(a), a_y2 = get<3>(a);
  int b_x1 = get<0>(b), b_y1 = get<1>(b), b_x2 = get<2>(b), b_y2 = get<3>(b);

  return (b_x1 < a_x1 && a_x2 < b_x2) && (b_y1 < a_y1 && a_y2 < b_y2);
}

bool IsOriginOnSegment(int x, int y1, int y2) {
  return (x == 0 && y1 <= 0 && 0 <= y2);
}

bool IsOriginOnRect(const tuple<int, int, int, int>& rect) {
  int x1 = get<0>(rect), y1 = get<1>(rect), x2 = get<2>(rect), y2 = get<3>(rect);
  return IsOriginOnSegment(x1, y1, y2) || IsOriginOnSegment(x2, y1, y2) || IsOriginOnSegment(y1, x1, x2) || IsOriginOnSegment(y2, x1, x2);
}

vector<int> adj_list[1005];
bool visited[1005];

void Dfs(int x) {
  for (auto y : adj_list[x]) {
    if (visited[y]) continue;
    visited[y] = true;
    Dfs(y);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  bool is_origin_on_rect = false;
  for (int i = 0; i < n; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    rects[i] = make_tuple(x1, y1, x2, y2);
    if (is_origin_on_rect == false && IsOriginOnRect(rects[i])) {
      is_origin_on_rect = true;
    }
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (IsOverlapRect(rects[i], rects[j]) 
      && (!IsIncludedRect(rects[i], rects[j]) 
      && !IsIncludedRect(rects[j], rects[i]))) {
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
      }
    }
  }

  int ans = is_origin_on_rect ? -1 : 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i] == false) {
      visited[i] = true;
      ans++;
      Dfs(i); 
    }
  }

  cout << ans << "\n";

  return 0;
}
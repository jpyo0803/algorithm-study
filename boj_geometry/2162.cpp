// 선분 그룹
// https://www.acmicpc.net/problem/2162

#include <bits/stdc++.h>

using namespace std;

int n;

pair<pair<int, int>, pair<int, int>> segments[3005];

vector<int> adj_list[3005];
bool visited[3005];

int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  auto v1 = make_pair(p2.first - p1.first, p2.second - p1.second);
  auto v2 = make_pair(p3.first - p1.first, p3.second - p1.second);
  int res = v1.first * v2.second - v1.second * v2.first;
  if (res > 0) return 1;
  else if (res < 0) return -1;
  return 0;
}

bool IsPointOnSegment(pair<pair<int, int>, pair<int, int>> ls, pair<int, int> p) {
  int x1 = ls.first.first, x2 = ls.second.first;
  int y1 = ls.first.second, y2 = ls.second.second;
  int x = p.first, y  = p.second;
  return min(x1, x2) <= x && x <= max(x1, x2) && min(y1, y2) <= y && y <= max(y1, y2);
}

bool IsIntersect(pair<pair<int, int>, pair<int, int>> s1, pair<pair<int, int>, pair<int, int>> s2) {
  pair<int, int> p1 = s1.first, p2 = s1.second, p3 = s2.first, p4 = s2.second;
  int a = CCW(p1, p2, p3) * CCW(p1, p2, p4);
  int b = CCW(p3, p4, p1) * CCW(p3, p4, p2);

  if (a < 0 && b < 0) return true;
  else if (a == 0 && b < 0) return true;
  else if (a < 0 && b == 0) return true;

  if (a == 0 && b == 0) { // Colinear
    if (IsPointOnSegment(s1, p3) || IsPointOnSegment(s1, p4) || IsPointOnSegment(s2, p1) || IsPointOnSegment(s2, p2)) {
      return true;
    }
  }
  return false;
}

int Dfs(int x) {
  int cnt = 1; // count myself

  for (auto y : adj_list[x]) {
    if (visited[y] == false) {
      visited[y] = true;
      cnt += Dfs(y);
    }
  }

  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> segments[i].first.first >> segments[i].first.second >> segments[i].second.first >> segments[i].second.second;
  }

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (IsIntersect(segments[i], segments[j])) {
        adj_list[i].push_back(j);
        adj_list[j].push_back(i);
      }
    }
  }

  int group_cnt = 0;
  int max_cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (visited[i] == false) {
      visited[i] = true;
      group_cnt++;
      max_cnt = max(max_cnt, Dfs(i));
    }
  }

  cout << group_cnt << "\n";
  cout << max_cnt << "\n";

  return 0;
}
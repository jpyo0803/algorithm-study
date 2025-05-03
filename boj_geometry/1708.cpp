// 볼록 껍질
// https://www.acmicpc.net/problem/1708

#include <bits/stdc++.h>

using namespace std;

int n;

int CCW(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3) {
  pair<int, int> v1 = make_pair(p2.first - p1.first, p2.second - p1.second);
  pair<int, int> v2 = make_pair(p3.first - p1.first, p3.second - p1.second);
  long long res =
      (long long)v1.first * v2.second - (long long)v1.second * v2.first;
  if (res > 0)
    return 1;  // ccw
  else if (res < 0)
    return -1;  // cw
  return 0;     // colinear
}

vector<pair<int, int>> ConvexHull(vector<pair<int, int>> pts) {
  if (pts.size() < 3)
    return {};
  else if (pts.size() == 3)
    return pts;
  vector<pair<int, int>> lower_ans, upper_ans;
  sort(pts.begin(), pts.end());

  // Construct lower convex hull
  for (auto pt : pts) {
    int x = pt.first, y = pt.second;
    while (lower_ans.size() >= 2 &&
           CCW(lower_ans[lower_ans.size() - 2], lower_ans[lower_ans.size() - 1],
               pt) <= 0) {
      lower_ans.pop_back();
    }
    lower_ans.push_back(pt);
  }

  // Construct upper convex hull
  for (int i = pts.size() - 1; i >= 0; --i) {
    auto pt = pts[i];
    int x = pt.first, y = pt.second;
    while (upper_ans.size() >= 2 &&
           CCW(upper_ans[upper_ans.size() - 2], upper_ans[upper_ans.size() - 1],
               pt) <= 0) {
      upper_ans.pop_back();
    }
    upper_ans.push_back(pt);
  }
  for (int i = 1; i < upper_ans.size() - 1; ++i) {
    lower_ans.push_back(upper_ans[i]);
  }
  return lower_ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<pair<int, int>> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i].first >> arr[i].second;
  }

  auto ans = ConvexHull(arr);
  cout << ans.size() << "\n";

  return 0;
}
// Why Did The Cow Cross The Road (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=714

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  // cout.tie(nullptr);

  ifstream fin("helpcross.in");
  ofstream fout("helpcross.out");

  int c, n;
  fin >> c >> n;

  vector<int> cv(c);
  for (int i = 0; i < c; ++i) fin >> cv[i];

  vector<pair<int, int>> vv(n);
  for (auto& e : vv) fin >> e.first >> e.second;

  sort(cv.begin(), cv.end());
  sort(vv.begin(), vv.end());

  priority_queue<int> pq;
  int i = 0;
  int ans = 0;
  for (auto e : cv) {
    while (pq.size() && -pq.top() < e) pq.pop();
    while (i < n && vv[i].second < e) i++;
    while (i < n && vv[i].first <= e && e <= vv[i].second) {
      pq.push(-vv[i].second);
      i++;
    }

    if (pq.empty()) continue;

    pq.pop();
    ans++;
  }

  fout << ans << "\n";

  return 0;
}
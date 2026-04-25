// Room Allocation
// https://cses.fi/problemset/task/1164

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int ans = 0;
  vector<int> ansv(n);
  vector<tuple<int, int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(v[i]) >> get<1>(v[i]);
    get<2>(v[i]) = i;
  }

  sort(v.begin(), v.end());

  priority_queue<pair<int, int>> pq;
  int t = 1;

  for (auto ee : v) {
    int s, e, id;
    tie(s, e, id) = ee;
    int rn;
    if (pq.size() && -pq.top().first < s) {
      rn = pq.top().second;
      pq.pop();
    } else {
      rn = t++;
    }

    pq.push({-e, rn});
    ansv[id] = rn;
    ans = max(ans, (int)pq.size());
  }

  cout << ans << "\n";
  for (auto e : ansv) cout << e << " ";
  cout << "\n";

  return 0;
}
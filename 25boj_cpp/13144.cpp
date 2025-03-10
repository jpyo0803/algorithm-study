// List of Unique Numbers
// https://www.acmicpc.net/problem/13144

#include <bits/stdc++.h>

using namespace std;

int n;

long long Count(int x) { return (long long)x * (x + 1) / 2; }

int seen_from[100010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> vv(n);
  for (int i = 0; i < n; ++i) cin >> vv[i];
  for (int i = 1; i <= 1e5; ++i) seen_from[i] = -1;

  // Inc-Exc principle
  vector<pair<int, int>> lst;

  int l = 0;
  for (int i = 0; i < n; ++i) {
    int x = vv[i];
    if (seen_from[x] < l) {
      // first seen
      seen_from[x] = i;
    } else {
      lst.emplace_back(
          l, i - 1);  // i-1 is safe as when i == 0, it is first element
      l = seen_from[x] + 1;
      seen_from[x] = i;
    }
  }

  lst.emplace_back(l, n - 1);
  // for (auto e : lst) {
  //   cout << e.first << ", " << e.second << endl;
  // }

  long long ans = 0;

  int last_r = -1;
  for (int i = 0; i < lst.size(); ++i) {
    ans += Count(lst[i].second - lst[i].first + 1);
    ans -= Count(last_r - lst[i].first + 1);
    last_r = lst[i].second;
  }

  cout << ans << "\n";

  return 0;
}
// Paired Up (Silver)
// https://www.acmicpc.net/problem/14527

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> av(n);
  for (int i = 0; i < n; ++i) cin >> av[i].second >> av[i].first;
  // time, count

  sort(av.begin(), av.end());

  int ans = 0;
  int l = 0, r = n - 1;

  while (l <= r) {
    int amt;
    if (l == r)
      amt = av[l].second / 2;
    else
      amt = min(av[l].second, av[r].second);

    ans = max(ans, av[l].first + av[r].first);
    av[l].second -= amt;
    av[r].second -= amt;
    if (av[l].second == 0) l++;
    if (av[r].second == 0) r--;
  }
  
  cout << ans << "\n"; 

  return 0;
}
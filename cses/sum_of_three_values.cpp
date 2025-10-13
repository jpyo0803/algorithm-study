// Sum of Three Values
// https://cses.fi/problemset/task/1641

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;
  if (n < 3) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  vector<pair<int, int>> av(n);
  for (int i = 0; i < n; ++i) {
    cin >> av[i].first;
    av[i].second = i;
  }

  sort(av.begin(), av.end());

  for (int i = 0; i < n; ++i) {
    int t = x - av[i].first;
    if (t < 2) continue;

    int l = 0, r = n - 1;
    while (l < r) {
      if (l == i) l++;
      if (r == i) r--;
      int sum = av[l].first + av[r].first;
      if (sum > t)
        r--;
      else if (sum < t)
        l++;
      else {
        array<int, 3> ans = {av[i].second, av[l].second, av[r].second};
        sort(ans.begin(), ans.end());
        for (auto e : ans) {
          cout << e + 1 << " ";
        }
        cout << "\n";
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE\n";

  return 0;
}
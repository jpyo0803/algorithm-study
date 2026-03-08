// Ferris Wheel
// https://cses.fi/problemset/task/1090

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> v(n);
  multiset<int> ms;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    ms.insert(v[i]);
  }
  
  sort(v.begin(), v.end());

  int ans = 0;
  for (int i = 0; i < n && ms.size() >= 2; ++i) {
    auto it = ms.find(v[i]);
    if (it == ms.end()) continue;
    ms.erase(it);
    ans++;
    auto it2 = ms.upper_bound(x - v[i]);
    if (ms.begin() != it2) {
      it2--;
      ms.erase(it2);
    }
  }

  cout << ans + ms.size() << "\n";

  return 0;
}
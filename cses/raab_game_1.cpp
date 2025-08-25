// Raab Game I
// https://cses.fi/problemset/task/3399

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int n, a, b;
    cin >> n >> a >> b;
    if (a + b > n || (!a && b) || (a && !b)) {
      cout << "NO\n";
      continue;
    }

    int s = a + b;
    int d = n - s;
    cout << "YES\n";

    vector<int> av(n), bv(n);

    for (int i = 0; i < n; ++i) {
      av[i] = i + 1;
      bv[i] = i < s ? (min(a, b) + i) % s + 1 : i + 1;
    }

    if (a > b) swap(av, bv);

    for (auto e : av) cout << e << " ";
    cout << "\n";
    for (auto e : bv) cout << e << " ";
    cout << "\n";
  }

  return 0;
}
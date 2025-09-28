// N. Nusret Gökçe
// https://codeforces.com/gym/104114/problem/N

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];

  int ma = 0;
  for (int i = 0; i < n; ++i) {
    ma = max(v[i], ma - m);
    v[i] = ma;
  }

  for (int i = n - 1; i >= 0; --i) {
    ma = max(v[i], ma - m);
    v[i] = ma;
  }

  for (auto e : v) {
    cout << e << " ";
  }
  cout << "\n";

  return 0;
}
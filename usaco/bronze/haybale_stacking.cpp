// Haybale Stacking (Bronze)
// https://www.acmicpc.net/problem/5912

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  vector<int> ps(n + 1, 0);
  while (k--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    ps[a]++, ps[b + 1]--;
  }

  for (int i = 1; i <= n; ++i) ps[i] += ps[i - 1];

  sort(ps.begin(), ps.end());
  cout << ps[n / 2 + 1] << "\n";

  return 0;
}
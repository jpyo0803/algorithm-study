// Karen and Coffee
// https://codeforces.com/contest/816/problem/B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k, q;
int da[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k >> q;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    da[a]++, da[b + 1]--;
  }
  for (int i = 1; i <= 2e5; ++i) da[i] += da[i - 1];

  for (int i = 1; i <= 2e5; ++i) da[i] >= k ? da[i] = 1 : da[i] = 0;

  for (int i = 1; i <= 2e5; ++i) da[i] += da[i - 1];

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << da[b] - da[a - 1] << "\n";
  }

  return 0;
}
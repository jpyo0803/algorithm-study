// Made Up
// https://atcoder.jp/contests/abc202/tasks/abc202_c?lang=en

#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005];
int b[100005];
int c[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) cin >> c[i];

  map<int, int> mm;
  for (int i = 0; i < n; ++i) mm[a[i]]++;

  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += mm[b[c[i] - 1]];
  }
  cout << ans << "\n";

  return 0;
}
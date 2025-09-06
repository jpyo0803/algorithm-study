// 보물
// https://www.acmicpc.net/problem/1026

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i]; 
  for (int i = 0; i < n; ++i) cin >> b[i];
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] * b[n - i - 1];
  }
  cout << ans << "\n";

  return 0;
}
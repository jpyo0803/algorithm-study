// 시험 감독
// https://www.acmicpc.net/problem/13458

#include <bits/stdc++.h>

using namespace std;

int n, b, c;
int a[1000005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) cin >> a[i];
  
  cin >> b >> c;
  long long ans = 0;

  for (int i = 0; i < n; ++i) {
    ans += max(0, (a[i] - b + c - 1) / c) + 1;
  }

  cout << ans << "\n";

  return 0;
}
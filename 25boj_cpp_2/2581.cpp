// 소수
// https://www.acmicpc.net/problem/2581

#include <bits/stdc++.h>

using namespace std;

int m, n;

int sum = 0;
int min_val = -1;
bool chk[10005];

void Eras() {
  for (int i = 2; i <= n; ++i) {
    if (chk[i]) continue;
    if (i >= m && i <= n) {
      sum += i;
      if (min_val == -1) min_val = i;
    }
    for (int j = i * i; j <= n; j += i) chk[j] = true;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n;
  if (m > n) {
    cout << "-1\n";
    return 0;
  }

  Eras();

  if (min_val == -1) cout << "-1\n";
  else cout << sum << "\n" << min_val << "\n";

  return 0;
}
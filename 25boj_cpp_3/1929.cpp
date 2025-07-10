// 소수 구하기 
// https://www.acmicpc.net/problem/1929

#include <bits/stdc++.h>

using namespace std;

bool chk[1000005];

int m, n;

vector<int> Eras() {
  vector<int> pn;
  for (int i = 2; i <= 1e6; ++i) {
    if (chk[i]) continue;
    if (i >= m && i <= n) cout << i << "\n";
    for (long long j = (long long)i * i; j <= 1e6; j += i) {
      chk[j] = true;
    }
  }
  return pn;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n;
  Eras();
  return 0;
}
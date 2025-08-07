// 소수 찾기 
// https://www.acmicpc.net/problem/1978

#include <bits/stdc++.h>

using namespace std;

int n;

bool IsPrime(int x) {
  if (x <= 1) return false;
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  
  int ans = 0;
  while (n--) {
    int x;
    cin >> x;
    if (IsPrime(x)) ans++;
  }
  cout << ans << "\n";

  return 0;
}
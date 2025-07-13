// 1로 만들기 
// https://www.acmicpc.net/problem/1463

#include <bits/stdc++.h>

using namespace std;

int n;
int dp[1000005]; // 1부터 x가 되기까지 필요한 연산의 수

int Solve(int x) {
  if (x == 1) return 0;
  if (dp[x] != -1) return dp[x];

  int ret = 1e9;
  if (x % 3 == 0) ret = min(ret, Solve(x / 3));
  if (x % 2 == 0) ret = min(ret, Solve(x / 2));
  ret = min(ret, Solve(x - 1));
  dp[x] = ret + 1;
  return dp[x];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i) dp[i] = -1;

  cout << Solve(n) << "\n";

  return 0;
}
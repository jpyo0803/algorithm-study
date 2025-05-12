// 계단 오르기 
// https://www.acmicpc.net/problem/2579


/*
  if stepped at x, (x-1 stepped and x-2 not stepped) or (x-1 not stepped and x-2 stepped) 
  * x-1 not stepped and x-2 not stepped is not possible as there is no way you can step at x

  if not stepped at x, (x-1 stepped and x-2 stepped) or (x-1 stepped and x-2 not stepped) or (x-1 not stepped and x-2 stepped) 

*/
#include <bits/stdc++.h>

using namespace std;

int n;
int arr[305];
int dp[305][3]; // dp[x][연속으로 선택된 횟수] 

int Solve(int x, int y) {
  if (x < 0) return 0;
  if (dp[x][y] != -1) return dp[x][y];

  int ret = 0;

  if (y == 0) {
    ret = max(ret, Solve(x - 1, 1));
    ret = max(ret, Solve(x - 1, 2));
  } else {
    ret = max(ret, Solve(x - 1, y - 1) + arr[x]);
  }

  dp[x][y] = ret;
  return dp[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) { // arr[0] = 0
    cin >> arr[i];
    dp[i][0] = dp[i][1] = dp[i][2] = -1;
  }

  int ans = 0;
  for (int i = 1; i <= 2; ++i) ans = max(ans, Solve(n - 1, i));
  cout << ans << "\n";

  return 0;
}
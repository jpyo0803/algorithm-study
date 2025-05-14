// 비밀번호
// https://www.acmicpc.net/problem/2780

#include <bits/stdc++.h>

using namespace std;

constexpr int kMod = 1234567;

int dp[10][1005];

int t, n;

vector<int> get_next[10];

int Solve(int x, int y) { // x = curr number, y = remaining digit
  if (y == 1) return 1;
  if (dp[x][y] != -1) return dp[x][y];

  int ret = 0;
  for (int next : get_next[x]) {
    ret += Solve(next, y - 1);
    ret %= kMod;
  }
  dp[x][y] = ret;
  return dp[x][y];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  get_next[0] = {7};
  get_next[1] = {2, 4};
  get_next[2] = {1, 3, 5};
  get_next[3] = {2, 6};
  get_next[4] = {1, 5, 7};
  get_next[5] = {2, 4, 6, 8};
  get_next[6] = {3, 5, 9};
  get_next[7] = {0, 4, 8};
  get_next[8] = {5, 7, 9};
  get_next[9] = {6, 8};

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 1005; ++j) {
      dp[i][j] = -1;
    }
  }

  cin >> t;
  while (t--) {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < 10; ++i) {
      ans += Solve(i, n);
      ans %= kMod;
    }
    cout << ans << "\n";
  }

  return 0;
}
// 팰린드롬?
// https://www.acmicpc.net/problem/10942

#include <bits/stdc++.h>

using namespace std;

bool dp[2010][2010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> nums(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> nums[i];
  }

  // for odd
  for (int i = 1; i <= N; ++i) {
    dp[i][i] = true;

    int j = 1;
    bool ok = true;
    while (i - j >= 1 && i + j <= N) {
      if (nums[i - j] != nums[i + j]) {
        ok &= false;
      }
      dp[i - j][i + j] = ok;
      j++;
    }
  }

  // for even
  for (int i = 1; i < N; ++i) {
    int l = i;
    int r = i + 1;

    bool ok = true;
    while (l >= 1 && r <= N) {
      if (nums[l] != nums[r]) {
        ok &= false;
      }
      dp[l][r] = ok;
      l--;
      r++;
    }
  }

  int M;
  cin >> M;
  while (M--) {
    int s, e;
    cin >> s >> e;
    cout << dp[s][e] << "\n";
  }

  return 0;
}
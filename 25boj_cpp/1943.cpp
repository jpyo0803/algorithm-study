// 동전 분배
// https://www.acmicpc.net/problem/1943

#include <bits/stdc++.h>

using namespace std;

pair<int, int> vc[105];
bool dp[50010];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int t = 0; t < 3; ++t) {
    int n;
    cin >> n;

    int total_amt = 0;

    for (int i = 0; i < n; ++i) {
      cin >> vc[i].first >> vc[i].second;
      total_amt += vc[i].first * vc[i].second;
    }

    if (total_amt % 2) {
      cout << "0\n";
      continue;
    }

    int target_amt = total_amt / 2;
    for (int i = 0; i <= target_amt; ++i) dp[i] = false;

    dp[0] = true;

    for (int i = 0; i < n; ++i) {
      int coin = vc[i].first;
      int cnt = vc[i].second;

      for (int j = target_amt; j >= 0; j--) {
        if (dp[j] == true) {
          for (int k = 1; k <= cnt && j + coin * k <= target_amt; ++k) {
            dp[j + coin * k] = true;
          }
        }
      }
    }

    cout << dp[target_amt] << "\n";
  }

  return 0;
}
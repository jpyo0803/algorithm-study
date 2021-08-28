//
// Zoo
// Problem: https://www.acmicpc.net/problem/1309
// Comment: Memoization may not succeed in your environment when input size is
// very big due to stack size constraint
//

#include <iostream>

#define MODE 1  // 0 = Memoization, 1 = Tabulation

using namespace std;

const int MAX_SIZE{100000};
const int DIV_MOD{9901};
int N;
int dp[MAX_SIZE + 1][3];

#if (MODE == 0)
bool filled[MAX_SIZE + 1][3];
int memo_method(int i, int j) {
  if (i == 1) return 1;
  if (filled[i][j]) return dp[i][j];

  for (int k = 0; k < 3; k++) {
    if (j != 0 && j == k) continue;
    dp[i][j] =
        ((dp[i][j] % DIV_MOD) + (memo_method(i - 1, k) % DIV_MOD)) % DIV_MOD;
  }
  filled[i][j] = true;
  return dp[i][j];
}
#else
int tabulate_method(int n) {
  for (int j = 0; j < 3; j++) dp[1][j] = 1;

  for (int i = 2; i <= n; i++) {
    dp[i][0] = ((dp[i - 1][0] % DIV_MOD) + (dp[i - 1][1] % DIV_MOD) +
                (dp[i - 1][2] % DIV_MOD)) %
               DIV_MOD;
    dp[i][1] = ((dp[i - 1][0] % DIV_MOD) + (dp[i - 1][2] % DIV_MOD)) % DIV_MOD;
    dp[i][2] = ((dp[i - 1][0] % DIV_MOD) + (dp[i - 1][1] % DIV_MOD)) % DIV_MOD;
  }

  return ((dp[n][0] % DIV_MOD) + (dp[n][1] % DIV_MOD) + (dp[n][2] % DIV_MOD)) %
         DIV_MOD;
}
#endif

int main() {
  cin >> N;

#if (MODE == 0)
  cout << "Memoization" << endl;
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    ans = ((ans % DIV_MOD) + (memo_method(N, i) % DIV_MOD)) % DIV_MOD;
  }
  cout << ans;
#else
  cout << "Tabulation" << endl;
  cout << tabulate_method(N);
#endif
  return 0;
}

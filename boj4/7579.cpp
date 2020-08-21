//
// App
// Link: https://www.acmicpc.net/problem/7579
//

#include <cstdio>

int max(int x, int y) { return x > y ? x : y; }
int min(int x, int y) { return x < y ? x : y; }

constexpr int kMaxNum = 100;
constexpr int kMaxVal = 10000;

using namespace std;

int N, M;
int memories[kMaxNum];
int costs[kMaxNum];
int dp[kMaxVal + 1];

int tabulate_method() {
  dp[0] = 0;
  int ans = 987654321;
  for (int i = 0; i < N; i++) {
    for (int j = kMaxVal - costs[i]; j >= 0; j--) {
      if (dp[j] != -1) {
        dp[j + costs[i]] = max(dp[j + costs[i]], dp[j] + memories[i]);
      }
    }
  }

  for (int i = 0; i <= kMaxVal; i++) {
    if (dp[i] != -1 && dp[i] >= M) return i;
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i <= kMaxVal; i++) dp[i] = -1;
  for (int i = 0; i < N; i++) scanf("%d", &memories[i]);
  for (int i = 0; i < N; i++) scanf("%d", &costs[i]);

  printf("%d\n", tabulate_method());
  return 0;
}
// 텀 프로젝트
// https://www.acmicpc.net/problem/9466

#include <stdio.h>

using namespace std;

int T, N;
int choice[100010];
int check[100010];
int group_check[100010];
int ans;

void Dfs(int x, int depth, int group) {
  check[x] = depth;
  group_check[x] = group;
  if (check[choice[x]] == -1 && group_check[choice[x]] == -1) {
    Dfs(choice[x], depth + 1, group);
  } else if (group_check[choice[x]] == group) {
    ans += depth - check[choice[x]] + 1;
  }
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; ++t) {
    scanf("%d", &N);
    ans = 0;

    for (int n = 0; n < N; ++n) {
      int x;
      scanf("%d", &x);
      --x;
      choice[n] = x;
      check[n] = group_check[n] = -1;
    }

    for (int n = 0; n < N; ++n) {
      if (check[n] == -1 && group_check[n] == -1) {
        Dfs(n, 0, n);
      }
    }

    printf("%d\n", N - ans);
  }

  return 0;
}
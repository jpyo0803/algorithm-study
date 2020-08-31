//
// 방 배정하기
// Link: https://www.acmicpc.net/problem/14697
//

#include <cstdio>

using namespace std;

int N;
int W[3];
bool ans = false;

void DFS(int sum_upto_now, int depth) {
  if (ans) return;
  if (depth == 3) {
    if (sum_upto_now == N) ans = true;
    return;
  }

  for (int i = 0; i * W[depth] <= (N - sum_upto_now); i++) {
    DFS(sum_upto_now + W[depth] * i, depth + 1);
  }
}

int main() {
  for (int i = 0; i < 3; i++) scanf("%d", &W[i]);
  scanf("%d", &N);
  DFS(0, 0);
  printf("%d\n", ans);
  return 0;
}
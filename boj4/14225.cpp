//
// 부분수열의 합
// Link: https://www.acmicpc.net/problem/14225
//

#include <cstdio>

int N;
int S[20];
bool freq[2000000];

void DFS(int sum, int nth) {
  if (nth == N) {
    freq[sum] = true;
    return;
  }

  DFS(sum, nth + 1);
  DFS(sum + S[nth], nth + 1);
}

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &S[i]);
  }

  DFS(0, 0);
  int i = 1;
  int ans;
  while (true) {
    if (!freq[i]) {
      ans = i;
      break;
    }
    i++;
  }
  printf("%d\n", ans);

  return 0;
}
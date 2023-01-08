//
// Treasure
// Problem: https://www.acmicpc.net/problem/1026
//

#include <algorithm>
#include <cstdio>
const int MAX{50};
int N;
int A[MAX];
int B[MAX];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  for (int i = 0; i < N; i++) scanf("%d", &B[i]);

  std::sort(A, A + N);
  std::sort(B, B + N);

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += A[i] * B[N - 1 - i];
  }
  printf("%d", sum);
  return 0;
}

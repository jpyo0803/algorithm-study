// 구간 합 구하기 (펜윅 트리)
// https://www.acmicpc.net/problem/2042

#include <stdio.h>

int N, M, K, a, b;

long long arr[1000001];
long long tree[1000001];

long long Sum(int p) {
  long long sum = 0;
  while (p > 0) {
    sum += tree[p];
    p &= (p - 1);
  }
  return sum;
}

void Add(int p, long long v) {
  while (p <= N) {
    tree[p] += v;
    p += (p & -p);
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i++) scanf("%lld", &arr[i]);
  for (int i = 1; i <= N; i++) Add(i, arr[i]);

  for (int i = 0; i < M + K; i++) {
    scanf("%d%d", &a, &b);
    if (a == 1) {
      long long c;
      scanf("%lld", &c);
      Add(b, c - arr[b]);
      arr[b] = c;
    } else {
      int c;
      scanf("%d", &c);
      printf("%lld\n", Sum(c) - Sum(b - 1));
    }
  }

  return 0;
}

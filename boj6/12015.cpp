// 가장 긴 증가하는 부분 수열2
// https://www.acmicpc.net/problem/12015

#include <stdio.h>

int N;

int seq[1000000];
int index_tree[4000001];

int Max(int x, int y) { return x < y ? y : x; }

int Query(int s, int e) {
  int ret = 0;
  while (s <= e) {
    if (s % 2) ret = Max(ret, index_tree[s]), s++;
    if (e % 2 == 0) ret = Max(ret, index_tree[e]), e--;
    s >>= 1;
    e >>= 1;
  }
  return ret;
}

void Update(int n, int nv) {
  index_tree[n] = nv;
  while (n > 1) {
    if (index_tree[n] > index_tree[n / 2]) index_tree[n / 2] = index_tree[n];
    n >>= 1;
  }
}

int main() {
  scanf("%d", &N);

  int largest = 1;
  for (int n = 0; n < N; n++) {
    scanf("%d", &seq[n]);
    largest = Max(largest, seq[n]);
  }

  int base;
  for (base = 1; base < largest; base *= 2) {
  }

  for (int n = 0; n < N; n++) {
    int res = Query(base + 1, base + seq[n] - 1);
    Update(base + seq[n], res + 1);
  }

  printf("%d\n", Query(base + 1, base + largest));
  return 0;
}

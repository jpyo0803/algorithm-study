// 꼬인 전깃줄
// https://www.acmicpc.net/problem/1365

#include <stdio.h>

int Max(int x, int y) { return x < y ? y : x; }

int N;
int connections[100000];
int index_tree[200001];

int Query(int s, int e) {
  int ret = 0;
  while (s <= e) {
    if (s % 2) {
      ret = Max(ret, index_tree[s]);
      s++;
    }
    if (e % 2 == 0) {
      ret = Max(ret, index_tree[e]);
      e--;
    }
    s >>= 1;
    e >>= 1;
  }
  return ret;
}

void Update(int index, int new_value) {
  index_tree[index] = new_value;
  while (index > 1) {
    if (index_tree[index] > index_tree[index / 2]) {
      index_tree[index / 2] = index_tree[index];
    }
    index >>= 1;
  }
}

int main() {
  scanf("%d", &N);
  int largest = 1;
  for (int n = 0; n < N; n++) {
    scanf("%d", &connections[n]);
    largest = Max(largest, connections[n]);
  }

  int base;
  for (base = 1; base < N; base <<= 1) {
  }

  for (int n = 0; n < N; n++) {
    int res = Query(base + 1, base + connections[n] - 1);
    Update(base + connections[n], res + 1);
  }

  printf("%d\n", N - Query(base + 1, base + largest));
  return 0;
}

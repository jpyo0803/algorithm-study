// 구간 곱 구하기
// https://www.acmicpc.net/problem/11505

#include <stdint.h>
#include <stdio.h>

constexpr uint64_t kMod = 1000000007;

int N, M, K, a, b, c;

uint64_t index_tree[1000000 << 2];

uint64_t Multiply(uint64_t x, uint64_t y) { return (x * y) % kMod; }

uint64_t Query(int left, int right) {
  uint64_t ret = 1;

  while (left <= right) {
    if (right % 2 == 0) {
      ret = Multiply(ret, index_tree[right]);
      right--;
    }
    if (left % 2) {
      ret = Multiply(ret, index_tree[left]);
      left++;
    }
    left /= 2;
    right /= 2;
  }
  return ret;
}

void Update(int location, uint64_t new_value) {
  index_tree[location] = new_value;

  int i = location / 2;
  while (i > 0) {
    index_tree[i] = Multiply(index_tree[2 * i], index_tree[2 * i + 1]);
    i /= 2;
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &K);

  int base;
  for (base = 1; base < N; base <<= 1)
    ;

  for (int i = 0; i < N; i++) {
    uint64_t x;
    scanf("%llu", &x);
    index_tree[base + i] = x;
  }

  for (int i = base - 1; i > 0; i--) {
    index_tree[i] = Multiply(index_tree[2 * i], index_tree[2 * i + 1]);
  }

  for (int i = 0; i < M + K; i++) {
    scanf("%d%d%d", &a, &b, &c);
    if (a == 1) {  // Update
      Update(base + b - 1, c);
    } else {  // Print
      printf("%llu\n", Query(base + b - 1, base + c - 1));
    }
  }

  return 0;
}

//
// Tree Cutting
// Problem: https://www.acmicpc.net/problem/2805
//

#include <cstdint>
#include <cstdio>

const int MAX{1000000};
int N, M, ans{0};
int trees[MAX];

void BinarySearch(int l, int r) {
  if (l > r) return;
  int m = (l + r) / 2;

  uint64_t sum = 0;
  for (int i = 0; i < N; i++) {
    if (trees[i] > m) {
      sum += trees[i] - m;
    }
  }

  if (sum >= M) {
    if (ans < m) {
      ans = m;
    }
  }

  if (sum > M) {
    BinarySearch(m + 1, r);
  } else if (sum < M) {
    BinarySearch(l, m - 1);
  }
}

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%d", &trees[i]);
  }
  BinarySearch(0, 1000000000);
  printf("%d", ans);
  return 0;
}

// 카드 놓기
// https://www.acmicpc.net/problem/5568

#include <stdio.h>

#include <set>

using namespace std;

int N, K;
int cards[10];

int chosen[10];
bool used[10];

set<int> found;

int Solve(int nth) {
  if (nth == K) {
    int candidate = 0;
    for (int i = 0; i < K; i++) {
      int num = cards[chosen[i]];
      if (num >= 10)
        candidate = candidate * 100 + num;
      else
        candidate = candidate * 10 + num;
    }
    if (found.find(candidate) == found.end()) {
      found.insert(candidate);
      return 1;
    }
    return 0;
  }

  int sum = 0;
  for (int i = 0; i < N; i++) {
    if (used[i]) continue;
    used[i] = true;
    chosen[nth] = i;
    sum += Solve(nth + 1);
    used[i] = false;
  }
  return sum;
}

int main() {
  scanf("%d%d", &N, &K);
  for (int i = 0; i < N; i++) scanf("%d", &cards[i]);
  printf("%d\n", Solve(0));
  return 0;
}

//
// N and M 11
// Problem: https://www.acmicpc.net/problem/15665
//

#include <cstdio>
#include <iostream>
#include <map>

using namespace std;
const int MAX{8};
int N, M;
map<int, int> nums;
int chosen[MAX];

void solve(int nth) {
  if (nth == M) {
    for (int i = 0; i < M; i++) {
      printf("%d ", chosen[i]);
    }
    printf("\n");
    return;
  }

  for (auto &num : nums) {
    chosen[nth] = num.first;
    solve(nth + 1);
  }
};

int main() {
  scanf("%d%d", &N, &M);

  int e;
  for (int i = 0; i < N; i++) {
    scanf("%d", &e);
    nums[e] += 1;
  }

  solve(0);
  return 0;
}
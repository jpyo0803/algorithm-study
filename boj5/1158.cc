//
// 요세푸스 문제
// Link: https://www.acmicpc.net/problem/1158
//

#include <stdio.h>

#include <vector>

using namespace std;

int N, K;
int nums[5001];

vector<int> Solve(int N, int K) {
  vector<int> ans;
  for (int i = 1; i <= N; i++) nums[i] = i;

  int now = 0;
  while (N > 0) {
    now = (now + K) % N;
    if (now == 0) now = N;
    ans.push_back(nums[now]);
    for (int i = now; i < N; i++) nums[i] = nums[i + 1];
    now--;
    N--;
  }

  return ans;
}

int main() {
  scanf("%d%d", &N, &K);
  vector<int> ans = Solve(N, K);

  printf("<");
  for (int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
    if (i < ans.size() - 1) {
      printf(", ");
    }
  }
  printf(">");

  return 0;
}

// 요세푸스 문제 0
// https://www.acmicpc.net/problem/11866

#include <stdio.h>

#include <vector>

using namespace std;

int N, K;

int arr[1001];

vector<int> Solve(int N, int K) {
  vector<int> ans;
  for (int i = 1; i <= N; i++) arr[i] = i;

  int now = 0;
  while (N > 0) {
    now += K;
    now %= N;
    if (now == 0) now = N;
    ans.push_back(arr[now]);
    for (int i = now; i < N; i++) arr[i] = arr[i + 1];
    now--;
    N--;
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &K);
  auto ans = Solve(N, K);
  printf("<");
  for (int i = 0; i < ans.size(); i++) {
    printf("%d", ans[i]);
    if (i < ans.size() - 1) printf(", ");
  }
  printf(">");
  return 0;
}

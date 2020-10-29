//
// 로프
// Link: https://www.acmicpc.net/problem/2217
//

#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int ropes[100000];

int main() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &ropes[i]);
  }
  sort(ropes, ropes + N);

  int ans = 0;
  for (int i = 0; i < N; i++) {
    int v = ropes[i] * (N - i);
    ans = v > ans ? v : ans;
  }
  printf("%d\n", ans);
}
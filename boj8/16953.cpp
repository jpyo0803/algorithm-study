// A -> B
// https://www.acmicpc.net/problem/16953

#include <stdio.h>

#include <queue>
#include <utility>

using namespace std;

long long A, B;

int Solve() {
  queue<pair<long long, int>> que;
  que.emplace(A, 1);

  while (!que.empty()) {
    auto now = que.front();
    que.pop();
    if (now.first == B) return now.second;
    if (now.first * 2 <= B) que.emplace(now.first * 2, now.second + 1);
    if (now.first * 10 + 1 <= B)
      que.emplace(now.first * 10 + 1, now.second + 1);
  }
  return -1;
}

int main() {
  scanf("%lld%lld", &A, &B);
  printf("%d\n", Solve());
  return 0;
}
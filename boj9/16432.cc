// 떡장수와 호랑이
// https://www.acmicpc.net/problem/16432

#include <stdio.h>

#include <stack>
#include <vector>

using namespace std;

int N;

vector<int> rice_cakes[1'010];
bool visited[1'010][10];

bool done = false;
stack<int> ans;

void Solve(int nth, int prev_type) {
  if (done) return;
  if (nth == N) {
    done = true;
    return;
  }

  for (auto e : rice_cakes[nth]) {
    if (e == prev_type) continue;
    if (visited[nth][e]) continue;
    visited[nth][e] = true;
    Solve(nth + 1, e);
    if (done) {
      ans.push(e);
      return;
    }
  }
}

int main() {
  scanf("%d", &N);
  for (int n = 0; n < N; ++n) {
    int M;
    scanf("%d", &M);
    for (int m = 0; m < M; ++m) {
      int x;
      scanf("%d", &x);
      rice_cakes[n].push_back(x);
    }
  }

  Solve(0, -1);

  if (ans.empty()) {
    printf("-1\n");
  } else {
    while (!ans.empty()) {
      printf("%d\n", ans.top());
      ans.pop();
    }
  }
  return 0;
}
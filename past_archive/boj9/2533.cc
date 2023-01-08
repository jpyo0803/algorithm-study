// 사회망 서비스(SNS)
// https://www.acmicpc.net/problem/2533

#include <stdio.h>

#include <vector>

using namespace std;

vector<int> tree[1000010];
vector<int> relationship[1000010];
bool visited[1000010];
int cache[1000010][2];

int N;

int Min(int x, int y) { return x < y ? x : y; }

void Dfs(int x) {
  visited[x] = true;
  for (auto y : relationship[x]) {
    if (visited[y]) continue;
    tree[x].push_back(y);
    Dfs(y);
  }
}

int Solve(int x, bool chosen) {
  int& ret = cache[x][chosen];
  if (ret != -1) return ret;

  if (chosen) {
    ret = 1;
    for (auto y : tree[x]) {
      ret += Min(Solve(y, false), Solve(y, true));
    }
  } else {
    ret = 0;
    for (auto y : tree[x]) {
      ret += Solve(y, true);
    }
  }
  return ret;
}

int main() {
  scanf("%d", &N);
  for (int n = 1; n <= N; ++n) {
    cache[n][0] = cache[n][1] = -1;
  }

  for (int n = 0; n < N - 1; ++n) {
    int x, y;
    scanf("%d%d", &x, &y);
    relationship[x].push_back(y);
    relationship[y].push_back(x);
  }

  Dfs(1);
  printf("%d\n", Min(Solve(1, false), Solve(1, true)));
  return 0;
}
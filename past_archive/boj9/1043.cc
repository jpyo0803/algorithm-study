// 거짓말
// https://www.acmicpc.net/problem/1043

#include <stdio.h>

#include <set>
#include <vector>

using namespace std;

int N, M;
vector<int> xmen;
vector<int> graph[55];
vector<int> party[55];
set<int> already[55];

bool visited[55];

void Dfs(int x) {
  visited[x] = true;
  for (auto y : graph[x]) {
    if (visited[y]) continue;
    Dfs(y);
  }
}

int Solve() {
  for (auto xman : xmen) {
    if (visited[xman]) continue;
    Dfs(xman);
  }

  int ans = 0;
  for (int m = 0; m < M; ++m) {
    int count = 0;
    for (auto p : party[m]) {
      if (visited[p]) ++count;
    }
    if (count == 0) ++ans;
  }
  return ans;
}

int main() {
  scanf("%d%d", &N, &M);
  int x;
  scanf("%d", &x);
  for (int i = 0; i < x; ++i) {
    int y;
    scanf("%d", &y);
    xmen.push_back(y);
  }

  for (int m = 0; m < M; ++m) {
    scanf("%d", &x);
    int prev;
    for (int i = 0; i < x; ++i) {
      int y;
      scanf("%d", &y);
      party[m].push_back(y);
      if (i == 0) {
        prev = y;
        continue;
      }
      if (already[prev].find(y) == already[prev].end()) {
        graph[prev].push_back(y);
      }
      if (already[y].find(prev) == already[y].end()) {
        graph[y].push_back(prev);
      }
    }
  }

  printf("%d\n", Solve());
  return 0;
}
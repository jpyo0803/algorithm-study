//
// 삼각 그래프
// Link: https://www.acmicpc.net/problem/4883
//

#include <cstdio>
#include <cstring>

constexpr int INF = 987654321;

int Min(int x, int y) { return x < y ? x : y; }

int N;
int graph[100000][3];
int cache[100000][3];

int TriangleGraph() {
  cache[0][0] = INF;
  cache[0][1] = graph[0][1];
  cache[0][2] = graph[0][2] + cache[0][1];

  for (int r = 1; r < N; r++) {
    for (int c = 0; c < 3; c++) {
      cache[r][c] = INF;
      if (c - 1 >= 0) {
        cache[r][c] = Min(cache[r][c], cache[r][c - 1]);
        cache[r][c] = Min(cache[r][c], cache[r - 1][c - 1]);
      }
      cache[r][c] = Min(cache[r][c], cache[r - 1][c]);
      if (c + 1 < 3) {
        cache[r][c] = Min(cache[r][c], cache[r - 1][c + 1]);
      }
      cache[r][c] += graph[r][c];
    }
  }
  return cache[N - 1][1];
}

int main() {
  int k = 1;
  while (true) {
    scanf("%d", &N);
    if (N == 0) break;

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < 3; j++) {
        scanf("%d", &graph[i][j]);
        cache[i][j] = -INF;
      }
    }

    printf("%d. %d\n", k, TriangleGraph());
    k++;
  }
  return 0;
}
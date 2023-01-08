//
// 플로이드 2
// Link: https://www.acmicpc.net/problem/11780
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int INF = 987654321;

int N, M;
int adj[101][101];
int via[101][101];

void FloydWarshall() {
  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        int new_dist = adj[i][k] + adj[k][j];
        if (new_dist < adj[i][j]) {
          adj[i][j] = new_dist;
          via[i][j] = k;
        }
      }
    }
  }
}

void Reconstruct(int u, int v, vector<int>& path) {
  if (via[u][v] == -1) {
    path.push_back(u);
    if (u != v) path.push_back(v);
  } else {
    int w = via[u][v];
    Reconstruct(u, w, path);
    path.pop_back();
    Reconstruct(w, v, path);
  }
}

int main() {
  scanf("%d%d", &N, &M);

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j) adj[i][j] = INF;
      via[i][j] = -1;
    }
  }

  for (int m = 0; m < M; m++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    adj[u][v] = w < adj[u][v] ? w : adj[u][v];
  }

  FloydWarshall();

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      printf("%d ", adj[i][j]);
    }
    printf("\n");
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      vector<int> path;
      Reconstruct(i, j, path);
      if (path.size() < 2)
        printf("0\n");
      else {
        printf("%d ", path.size());
        for (auto e : path) {
          printf("%d ", e);
        }
        printf("\n");
      }
    }
  }

  return 0;
}

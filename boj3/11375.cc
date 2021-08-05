//
// 열혈강호
// Link: https://www.acmicpc.net/problem/11375
//

#include <cstdio>

constexpr int kMaxSize = 1000;
int N, M, num_task, task;

bool adj[kMaxSize + 1][kMaxSize + 1];
bool visited[kMaxSize + 1];
int a_matched[kMaxSize + 1];
int b_matched[kMaxSize + 1];

bool DFS(int a) {
  if (visited[a]) return false;
  visited[a] = true;

  for (int b = 1; b <= M; b++) {
    if (adj[a][b]) {
      if (b_matched[b] == -1 || DFS(b_matched[b])) {
        a_matched[a] = b;
        b_matched[b] = a;
        return true;
      }
    }
  }
  return false;
}
int main() {
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; i++) a_matched[i] = -1;
  for (int i = 1; i <= M; i++) b_matched[i] = -1;

  for (int i = 1; i <= N; i++) {
    scanf("%d", &num_task);
    for (int j = 0; j < num_task; j++) {
      scanf("%d", &task);
      adj[i][task] = true;
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) visited[j] = false;
    if (DFS(i)) {
      ans++;
    }
  }
  printf("%d", ans);
  return 0;
}


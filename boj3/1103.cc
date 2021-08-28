//
// Game
// Problem: https://www.acmicpc.net/problem/1103
//

#include <cstdio>
const int MAX{50};
char board[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int N, M;
int gmax{0};
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool found{false};
void dfs(int cr, int cc) {
  if (found) return;
  visited[cr][cc] = true;
  if (dp[cr][cc] > gmax) {
    gmax = dp[cr][cc];
  }

  for (int i = 0; i < 4; i++) {
    int nr = (board[cr][cc] - '0') * d[i][0] + cr;
    int nc = (board[cr][cc] - '0') * d[i][1] + cc;

    if (nr >= 0 && nr < N && nc >= 0 && nc < M && board[nr][nc] != 'H') {
      if (visited[nr][nc]) {
        gmax = -1;
        found = true;
        return;
      } else if (dp[cr][cc] + 1 > dp[nr][nc]) {
        dp[nr][nc] = dp[cr][cc] + 1;
        dfs(nr, nc);
      }
    }
  }

  visited[cr][cc] = false;
}

char buffer[MAX + 1];

int main() {
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", buffer);
    for (int j = 0; j < M; j++) {
      board[i][j] = buffer[j];
    }
  }

  dfs(0, 0);
  if (gmax != -1) gmax += 1;
  printf("%d", gmax);
  return 0;
}

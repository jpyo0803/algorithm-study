//
// Alphabet
// Problem: https://www.acmicpc.net/problem/1987
//

#include <iostream>

using namespace std;
const int MAX{20};
int R, C;
char map[MAX][MAX];
bool visited[26];

int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int ans{0};

void dfs(int ui, int uj, int level) {
  ans = max(ans, level);

  visited[map[ui][uj] - 'A'] = true;

  for (int i = 0; i < 4; i++) {
    int vi{ui + d[i][0]}, vj{uj + d[i][1]};
    if (vi >= 0 && vi < R && vj >= 0 && vj < C && !visited[map[vi][vj] - 'A']) {
      dfs(vi, vj, level + 1);
    }
  }

  visited[map[ui][uj] - 'A'] = false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> R >> C;
  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      cin >> map[r][c];
    }
  }
  dfs(0, 0, 1);
  cout << ans;
  return 0;
}

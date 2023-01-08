//
// 사다리 조작
// Link: https://www.acmicpc.net/problem/15684
//

#include <cstdio>

using namespace std;

constexpr int INF = 987654321;

int N, M, H, a, b, ans;
bool ladder[32][12];

int Min(int x, int y) { return x < y ? x : y; }

bool check() {
  for (int c = 1; c <= N; c++) {
    int cc = c;
    for (int r = 1; r <= H; r++) {
      if (ladder[r][cc - 1])
        cc -= 1;
      else if (ladder[r][cc])
        cc += 1;
    }
    if (cc != c) return false;
  }
  return true;
}

void DFS(int depth, int ns) {
  if (ans != INF) return;
  if (depth > ns) return;
  if (depth == ns) {
    if (check()) {
      ans = ns;
      return;
    }
  }
  for (int c = 1; c < N; c++) {
    for (int r = 1; r <= H; r++) {
      if (ladder[r][c] || ladder[r][c - 1] || ladder[r][c + 1]) continue;
      ladder[r][c] = true;
      DFS(depth + 1, ns);
      ladder[r][c] = false;
      while (r < H) {
        if (ladder[r][c - 1] || ladder[r][c + 1]) break;
        r++;
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &H);
  for (int i = 0; i < M; i++) {
    scanf("%d%d", &a, &b);
    ladder[a][b] = true;
  }

  ans = INF;
  for (int i = 0; i < 4; i++) {
    DFS(0, i);
    if (ans != INF) break;
  }
  printf("%d\n", ans == INF ? -1 : ans);

  return 0;
}

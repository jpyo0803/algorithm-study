//
// 색종이 붙이기
// Link: https://www.acmicpc.net/problem/17136
//

#include <cstdio>

constexpr int INF = 987654321;

bool InRange(int r, int c) { return r >= 0 && r < 10 && c >= 0 && c < 10; }
int Min(int x, int y) { return x < y ? x : y; }

int ans = INF;

struct Paper {
  bool arr[10][10];
  int paper_left[6] = {0, 5, 5, 5, 5, 5};

  bool TryCover(int r, int c, int edge) {
    if (!InRange(r + edge - 1, c + edge - 1)) return false;
    for (int i = r; i < r + edge; i++) {
      for (int j = c; j < c + edge; j++) {
        if (!arr[i][j]) return false;
      }
    }
    for (int i = r; i < r + edge; i++) {
      for (int j = c; j < c + edge; j++) {
        arr[i][j] = false;
      }
    }
    paper_left[edge]--;
    return true;
  }

  int GetPaperUsed() {
    int sum = 0;
    for (int i = 1; i < 6; i++) sum += paper_left[i];
    return 25 - sum;
  }
};
int e;

void DFS(Paper cp, int start_r, int start_c) {
  if (cp.GetPaperUsed() >= ans) return;

  int target_r = -1, target_c;
  int c = start_c;
  for (int r = start_r; r < 10 && target_r == -1; r++) {
    for (; c < 10; c++) {
      if (cp.arr[r][c]) {
        target_r = r;
        target_c = c;
        break;
      }
    }
    c = 0;
  }

  if (target_r == -1) {  // spot_to_cover = 0
    ans = cp.GetPaperUsed();
    return;
  }

  for (int edge = 5; edge > 0; edge--) {
    if (!cp.paper_left[edge]) continue;
    Paper np = cp;
    if (!np.TryCover(target_r, target_c, edge)) continue;
    int nr = target_r, nc = 0;
    if (target_c + edge >= 10) {  // next row
      nr += 1;
    } else {
      nc = target_c + edge;
    }

    DFS(np, nr, nc);
  }
  return;
}

int main() {
  Paper p;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      scanf("%d", &e);
      p.arr[i][j] = e;
    }
  }

  DFS(p, 0, 0);
  printf("%d\n", ans == INF ? -1 : ans);

  return 0;
}

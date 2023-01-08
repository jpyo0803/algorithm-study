//
// 구슬 탈출 2
// Link: https://www.acmicpc.net/problem/13460
//

#include <cstdio>
#include <cstring>

using namespace std;

constexpr int kMax = 10;
constexpr int INF = 987654321;
int N, M;

int Min(int x, int y) { return x < y ? x : y; }

struct Board {
  Board(int n, int m) : N(n), M(m) {}
  char arr[kMax][kMax];
  int N, M;
  int ri, rj;
  int bi, bj;

  void R90() {
    char temp_arr[kMax][kMax];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        temp_arr[j][N - 1 - i] = arr[i][j];
      }
    }
    int tmp;
    tmp = ri;
    ri = rj;
    rj = N - 1 - tmp;
    tmp = bi;
    bi = bj;
    bj = N - 1 - tmp;
    tmp = N;
    N = M;
    M = tmp;
    memcpy(arr, temp_arr, sizeof(arr));
  }

  bool Gravity(bool which) {  // false = blue, true = red
    int& si = which ? ri : bi;
    int& sj = which ? rj : bj;

    int i = si;
    while (i + 1 < N && arr[i + 1][sj] == '.') i++;

    if (arr[i + 1][sj] == 'O') {
      arr[si][sj] = '.';
      return true;
    }
    char tmp = arr[si][sj];
    arr[si][sj] = '.';
    arr[i][sj] = tmp;
    si = i;
    return false;
  }
};

int DFS(Board now, int nth) {
  int ret = INF;
  if (nth > 10) return ret;
  for (int i = 0; i < 4; i++) {
    Board next = now;
    bool res1, res2;
    if (next.ri > next.bi) {
      res1 = next.Gravity(true);
      res2 = next.Gravity(false);
    } else {
      res2 = next.Gravity(false);
      res1 = next.Gravity(true);
    }

    if (!res2) {
      if (res1)
        return nth;
      else
        ret = Min(ret, DFS(next, nth + 1));
    }
    now.R90();
  }
  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  Board b(N, M);

  for (int i = 0; i < N; i++) {
    char row[M + 1];
    scanf("%s", row);
    for (int j = 0; j < strlen(row); j++) {
      b.arr[i][j] = row[j];
      if (b.arr[i][j] == 'R') {
        b.ri = i;
        b.rj = j;
      } else if (b.arr[i][j] == 'B') {
        b.bi = i;
        b.bj = j;
      }
    }
  }

  int ans = DFS(b, 1);
  printf("%d\n", ans == INF ? -1 : ans);
  return 0;
}

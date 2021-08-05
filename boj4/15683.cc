//
// 감시
// Link: https://www.acmicpc.net/problem/15683
//

#include <cstdio>
#include <cstring>
#include <vector>

constexpr int kMax = 8;

constexpr int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};  //동북서남

int N, M;

using namespace std;

int Min(int x, int y) { return x < y ? x : y; }

struct Floor {
  Floor(int n, int m) : N(n), M(m) {}
  int N, M;
  int arr[kMax][kMax];
  int space_count = 0;
  int coverage_count = 0;

  bool InRange(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

  void DoCover(int sr, int sc, int dir) {  //동북서남
    int nr = sr + d[dir][0];
    int nc = sc + d[dir][1];

    while (InRange(nr, nc) && arr[nr][nc] != 6) {
      if (arr[nr][nc] == 0) {
        arr[nr][nc] = 7;
        coverage_count++;
      }
      nr += d[dir][0];
      nc += d[dir][1];
    }
  }
};

struct Camera {
  Camera(int _r, int _c) : r(_r), c(_c) {}
  int r, c;
};

vector<Camera> cameras;

int DFS(Floor cf, int nth) {
  if (nth == cameras.size()) {
    return cf.space_count - cf.coverage_count;
  }

  int ret = 987654321;
  int camera_type = cf.arr[cameras[nth].r][cameras[nth].c];
  if (camera_type == 1) {  //동북서남
    for (int i = 0; i < 4; i++) {
      Floor nf = cf;
      nf.DoCover(cameras[nth].r, cameras[nth].c, i);
      ret = Min(ret, DFS(nf, nth + 1));
    }
  } else if (camera_type == 2) {
    for (int i = 0; i < 2; i++) {
      Floor nf = cf;
      nf.DoCover(cameras[nth].r, cameras[nth].c, i);
      nf.DoCover(cameras[nth].r, cameras[nth].c, i + 2);
      ret = Min(ret, DFS(nf, nth + 1));
    }
  } else if (camera_type == 3) {
    for (int i = 0; i < 4; i++) {
      Floor nf = cf;
      nf.DoCover(cameras[nth].r, cameras[nth].c, i);
      nf.DoCover(cameras[nth].r, cameras[nth].c, ((i + 1) % 4)); // Damn it... i + 1 % 4 makes error
      ret = Min(ret, DFS(nf, nth + 1));
    }
  } else if (camera_type == 4) {
    for (int i = 0; i < 4; i++) {
      Floor nf = cf;
      nf.DoCover(cameras[nth].r, cameras[nth].c, i);
      nf.DoCover(cameras[nth].r, cameras[nth].c, ((i + 1) % 4));
      nf.DoCover(cameras[nth].r, cameras[nth].c, ((i + 2) % 4));
      ret = Min(ret, DFS(nf, nth + 1));
    }
  } else if (camera_type == 5) {
    Floor nf = cf;
    for (int i = 0; i < 4; i++) {
      nf.DoCover(cameras[nth].r, cameras[nth].c, i);
    }
    ret = Min(ret, DFS(nf, nth + 1));
  }

  return ret;
}

int main() {
  scanf("%d%d", &N, &M);
  Floor f(N, M);
  for (int i = 0; i < f.N; i++) {
    for (int j = 0; j < f.M; j++) {
      scanf("%d", &(f.arr[i][j]));
      if (f.arr[i][j] == 0) f.space_count++;
      if (f.arr[i][j] >= 1 && f.arr[i][j] <= 5) cameras.emplace_back(i, j);
    }
  }

  printf("%d\n", DFS(f, 0));

  return 0;
}
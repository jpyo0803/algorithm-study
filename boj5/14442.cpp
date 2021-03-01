//
// 벽부수고 이동하기 2
// Link: https://www.acmicpc.net/problem/14442
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<string> map;
vector<vector<vector<bool>>> visited;

int N, M, K;

struct Info {
  Info(int _r, int _c, int _s, int _k) : r(_r), c(_c), s(_s), k(_k) {}
  int r, c, s, k;
};

bool InRange(int r, int c) { return r >= 0 && r < N && c >= 0 && c < M; }

int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int Bfs() {
  queue<Info> que;
  que.emplace(0, 0, 1, 0);
  visited[0][0][0] = true;

  while (!que.empty()) {
    auto info = que.front();
    que.pop();
    int cr = info.r;
    int cc = info.c;
    int cs = info.s;
    int ck = info.k;
    if (cr == N - 1 && cc == M - 1) return info.s;

    for (int i = 0; i < 4; i++) {
      int nr = cr + d[i][0];
      int nc = cc + d[i][1];

      if (!InRange(nr, nc)) continue;
      if (map[nr][nc] == '1') {
        if (ck < K) {
          if (!visited[nr][nc][ck + 1]) {
            visited[nr][nc][ck + 1] = true;
            que.emplace(nr, nc, cs + 1, ck + 1);
          }
        }
      } else {
        if (!visited[nr][nc][ck]) {
          visited[nr][nc][ck] = true;
          que.emplace(nr, nc, cs + 1, ck);
        }
      }
    }
  }
  return -1;
}

int main() {
  cin >> N >> M >> K;
  map = vector<string>(N);
  visited = vector<vector<vector<bool>>>(
      N, vector<vector<bool>>(M, vector<bool>(K + 1, false)));

  for (int n = 0; n < N; n++) {
    string input;
    cin >> input;
    map[n] = input;
  }

  cout << Bfs() << endl;

  return 0;
}

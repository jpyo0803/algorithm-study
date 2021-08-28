//
// 배열 돌리기 4
// Link: https://www.acmicpc.net/problem/17406
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int kMax = 50;
constexpr int INF = 987654321;

int N, M, K, r, c, s, ans;

int array[kMax + 1][kMax + 1];

struct Rotation {
  Rotation(int _r, int _c, int _s) : r(_r), c(_c), s(_s) {}
  int r, c, s;
};

vector<Rotation> rotations;
bool used[6];

int Min(int x, int y) { return x < y ? x : y; }

void DoRotation(int array[][kMax + 1], Rotation& rot) {
  for (int layer = 1; layer <= rot.s; layer++) {
    vector<int> storage;
    for (int c = rot.c - layer; c < rot.c + layer; c++)
      storage.push_back(array[rot.r - layer][c]);
    for (int r = rot.r - layer; r < rot.r + layer; r++)
      storage.push_back(array[r][rot.c + layer]);
    for (int c = rot.c + layer; c > rot.c - layer; c--)
      storage.push_back(array[rot.r + layer][c]);
    for (int r = rot.r + layer; r > rot.r - layer; r--)
      storage.push_back(array[r][rot.c - layer]);

    array[rot.r - layer][rot.c - layer] = storage.back();
    int idx = 0;
    for (int c = rot.c - layer + 1; c < rot.c + layer; c++, idx++)
      array[rot.r - layer][c] = storage[idx];
    for (int r = rot.r - layer; r < rot.r + layer; r++, idx++)
      array[r][rot.c + layer] = storage[idx];
    for (int c = rot.c + layer; c > rot.c - layer; c--, idx++)
      array[rot.r + layer][c] = storage[idx];
    for (int r = rot.r + layer; r > rot.r - layer; r--, idx++)
      array[r][rot.c - layer] = storage[idx];
  }
}

void DFS(vector<int>& pv) {
  if (pv.size() == K) {
    int tmp_array[kMax + 1][kMax + 1];
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        tmp_array[i][j] = array[i][j];
      }
    }

    for (int i = 0; i < K; i++) DoRotation(tmp_array, rotations[pv[i]]);

    for (int i = 1; i <= N; i++) {
      int row_sum = 0;
      for (int j = 1; j <= M; j++) {
        row_sum += tmp_array[i][j];
      }
      ans = Min(ans, row_sum);
    }
    return;
  }

  for (int i = 0; i < K; i++) {
    if (used[i]) continue;
    used[i] = true;
    pv.push_back(i);
    DFS(pv);
    pv.pop_back();
    used[i] = false;
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      scanf("%d", &array[i][j]);
    }
  }

  for (int k = 0; k < K; k++) {
    scanf("%d%d%d", &r, &c, &s);
    rotations.emplace_back(r, c, s);
  }
  vector<int> permutation;

  ans = INF;
  DFS(permutation);

  printf("%d\n", ans);

  return 0;
}
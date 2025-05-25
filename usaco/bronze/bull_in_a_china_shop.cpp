// Bull in a China Shop (Bronze)
// https://www.acmicpc.net/problem/12006

#include <bits/stdc++.h>

using namespace std;

int N, K;

void PrintArr(const vector<vector<char>>& arr) {
  int n = arr.size();
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << arr[i][j];
    }
    cout << endl;
  }
}

bool SetupBoard(vector<vector<char>>& board, const vector<vector<char>>& piece_i, const vector<vector<char>>& piece_j, int off_i, int off_j) {
  bool ok = true;
  for (int i = 0; i < 3 * N; ++i) {
    for (int j = 0; j < 3 * N; ++j) {
      board[i][j] = '.';
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      board[i + N][j + N] = piece_i[i][j];
    }
  }
  
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (piece_j[i][j] != '#') continue;
      if (board[i + N + off_i][j + N + off_j] == '#') {
        // already there is '#', no overlapping allowed
        ok = false;
        break;
      }
      board[i + N + off_i][j + N + off_j] = piece_j[i][j];
    }
  }
  return ok;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> K;
  vector<vector<char>> orig(N, vector<char>(N));
  int orig_sharp_cnt = 0;
  vector<int> sharp_cnt_vec(K, 0);
  vector<vector<char>> board(3 * N + 5, vector<char>(3 * N + 5));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> orig[i][j];
      if (orig[i][j] == '#') orig_sharp_cnt++;
    }
  }

  vector<vector<vector<char>>> pieces(K, vector<vector<char>>(N, vector<char>(N)));
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < N; ++j) {
      for (int k = 0; k < N; ++k) {
        cin >> pieces[i][j][k];
        if (pieces[i][j][k] == '#') {
          sharp_cnt_vec[i]++;
        }
      }
    }
  }

  int ans_x = -1, ans_y;
  for (int i = 0; i < K - 1 && ans_x == -1; ++i) {
    for (int j = i + 1; j < K && ans_x == -1; ++j) {
      if (sharp_cnt_vec[i] + sharp_cnt_vec[j] != orig_sharp_cnt) continue;

      for (int off_i = -N; off_i <= N && ans_x == -1; ++off_i) {
        for (int off_j = -N; off_j <= N && ans_x == -1; ++off_j) {
          // cout << off_i << " / " << off_j << endl;
          if (SetupBoard(board, pieces[i], pieces[j], off_i, off_j) == false) continue;

          // PrintArr(board);
          // cout << "---------------" << endl;

          for (int off_i2 = -(N - 1); off_i2 <= N - 1 && ans_x == -1; ++off_i2) {
            for (int off_j2 = -(N - 1); off_j2 <= N - 1 && ans_x == -1; ++off_j2) {
              bool ok = true;
              for (int i2 = 0; i2 < N; ++i2) {
                for (int j2 = 0; j2 < N; ++j2) {
                  if (orig[i2][j2] != board[off_i2 + N + i2][off_j2 + N + j2]) {
                    ok = false;
                    break;
                  }
                }
              }
              if (ok) {
                ans_x = i + 1;
                ans_y = j + 1;
              }
            }
          }
        }
      }
    }
  }

  cout << ans_x << " " << ans_y << "\n";

  return 0;
}
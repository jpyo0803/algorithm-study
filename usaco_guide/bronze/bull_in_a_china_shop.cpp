// Bull in A China Shop
// http://www.usaco.org/index.php?page=viewproblem2&cpid=640

#include <bits/stdc++.h>

using namespace std;

char board[24][24];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, K;
  cin >> N >> K;

  set<pair<int, int>> orig;
  int start_x = -1, start_y;
  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < N; ++j) {
      if (s[j] == '.') continue;
      if (start_x == -1) {
        start_x = i;
        start_y = j;
      }
      orig.insert({i - start_x, j - start_y});
    }
  }

  vector<vector<string>> pieces(K, vector<string>(N));
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> pieces[i][j];
    }
  }

  int ans_x = -1, ans_y;
  for (int i = 0; i < K - 1; ++i) {
    for (int j = i + 1; j < K; ++j) {  // 45
      for (int x = 0; x <= 2 * N; ++x) {
        for (int y = 0; y <= 2 * N; ++y) {  // 289 * 45
          for (int a = 0; a < 3 * N; ++a) {
            for (int b = 0; b < 3 * N; ++b) {
              board[a][b] = '.';
            }
          }

          for (int a = 0; a < N; ++a) {
            for (int b = 0; b < N; ++b) {
              if (pieces[j][a][b] == '.') continue;
              board[N + a][N + b] = pieces[j][a][b];
            }
          }

          bool ok = true;
          for (int a = 0; a < N; ++a) {
            for (int b = 0; b < N; ++b) {
              if (pieces[i][a][b] == '.') continue;
              if (board[x + a][y + b] == '#') {  // overlap
                ok = false;
                break;
              }
              board[x + a][y + b] = pieces[i][a][b];
            }
            if (ok == false) break;
          }

          if (ok == false) continue;  // overlap, no further check is needed

          set<pair<int, int>> cand;
          int start_x = -1, start_y;
          for (int a = 0; a < 3 * N; ++a) {
            for (int b = 0; b < 3 * N; ++b) {
              if (board[a][b] == '.') continue;
              if (start_x == -1) {
                start_x = a;
                start_y = b;
              }
              cand.insert({a - start_x, b - start_y});
            }
          }

          if (orig == cand && ans_x == -1) {
            ans_x = i + 1;
            ans_y = j + 1;
          }
        }
      }
    }
  }

  cout << ans_x << " " << ans_y << "\n";

  return 0;
}
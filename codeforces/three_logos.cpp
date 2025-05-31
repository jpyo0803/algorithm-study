// Three Logos
// https://codeforces.com/problemset/problem/581/D

#include <bits/stdc++.h>

using namespace std;

pair<int, int> pieces[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 3; ++i) cin >> pieces[i].first >> pieces[i].second;

  vector<int> perm = {0, 1, 2};

  int ans = -1;
  int type;
  array<pair<int, int>, 3> ans_parr;
  char ans_ch[3];

  do {
    for (int state = 0; state < (1 << 3); ++state) {
      array<pair<int, int>, 3> parr;

      for (int i = 0; i < 3; ++i) {
        parr[i] = pieces[perm[i]];
        if ((state >> i) & 0b1) swap(parr[i].first, parr[i].second);
      }


      // case 1
      // y가 같고, 모든 x의 합은 y와 같아야함.
      if (parr[0].second == parr[1].second &&
          parr[1].second == parr[2].second &&
          parr[0].first + parr[1].first + parr[2].first == parr[0].second) {
        if (ans < parr[0].second) {
          ans = parr[0].second;
          type = 0;
          ans_parr = parr;
          for (int i = 0; i < 3; ++i) {
            ans_ch[i] = 'A' + perm[i];
          }
        }
      }

      // case 2
      if (parr[1].first == parr[2].first &&
          parr[1].second + parr[2].second == parr[0].second &&
          parr[0].first + parr[1].first == parr[0].second) {
        if (ans < parr[0].second) {
          ans = parr[0].second;
          type = 1;
          ans_parr = parr;
          for (int i = 0; i < 3; ++i) {
            ans_ch[i] = 'A' + perm[i];
          }
        }
      }
    }

  } while (next_permutation(perm.begin(), perm.end()));

  cout << ans << "\n";
  if (ans != -1) {
    vector<vector<char>> board(ans, vector<char>(ans));

    if (type == 0) {
      int offset_x = 0;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < ans_parr[i].first; ++j) {
          for (int k = 0; k < ans_parr[i].second; ++k) {
            board[j + offset_x][k] = ans_ch[i];
          }
        }
        offset_x += ans_parr[i].first;
      }
    } else {
      for (int i = 0; i < ans_parr[0].first; ++i) {
        for (int j = 0; j < ans_parr[0].second; ++j) {
          board[i][j] = ans_ch[0];
        }
      }

      int offset_x = ans_parr[0].first;
      for (int i = 0; i < ans_parr[1].first; ++i) {
        for (int j = 0; j < ans_parr[1].second; ++j) {
          board[i + offset_x][j] = ans_ch[1];
        }
        int offset_y = ans_parr[1].second;
        for (int j = 0; j < ans_parr[2].second; ++j) {
          board[i + offset_x][j + offset_y] = ans_ch[2];
        }
      }
    }

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[0].size(); ++j) {
        cout << board[i][j];
      }
      cout << "\n";
    }
  }

  return 0;
}
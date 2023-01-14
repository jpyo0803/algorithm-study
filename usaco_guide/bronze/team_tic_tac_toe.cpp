// Team Tic Tac Toe
// http://www.usaco.org/index.php?page=viewproblem2&cpid=831

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  char board[3][3];
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cin >> board[i][j];
    }
  }

  int one_team = 0, two_team = 0;

  auto is_victory = [&](const vector<char>& chs) {
    bool ok = false;

    // Check row
    for (int i = 0; i < 3; ++i) {
      int cnt = 0;
      set<char> used;
      for (int j = 0; j < 3; ++j) {
        // if at least one chars included, increment cnt
        for (auto ch : chs) {
          if (board[i][j] == ch) {
            ++cnt;
            used.insert(ch);
            break;
          }
        }
      }
      if (cnt == 3 && used.size() == chs.size()) {
        ok = true;
        break;
      }
    }

    // Check col
    for (int i = 0; !ok && i < 3; ++i) {
      int cnt = 0;
      set<char> used;
      for (int j = 0; j < 3; ++j) {
        for (auto ch : chs) {
          if (board[j][i] == ch) {
            ++cnt;
            used.insert(ch);
            break;
          }
        }
      }
      if (cnt == 3 && used.size() == chs.size()) {
        ok = true;
        break;
      }
    }

    // Check diag right down
    if (!ok) {
      int cnt = 0;
      set<char> used;
      for (int i = 0; i < 3; ++i) {
        for (auto ch : chs) {
          if (board[i][i] == ch) {
            ++cnt;
            used.insert(ch);
            break;
          }
        }
      }
      if (cnt == 3 && used.size() == chs.size()) {
        ok = true;
      }
    }

    // Check diag left down
    if (!ok) {
      int cnt = 0;
      set<char> used;
      for (int i = 0; i < 3; ++i) {
        for (auto ch : chs) {
          if (board[i][2 - i] == ch) {
            ++cnt;
            used.insert(ch);
            break;
          }
        }
      }
      if (cnt == 3 && used.size() == chs.size()) {
        ok == true;
      }
    }

    return ok;
  };

  // extract available initials
  vector<bool> check_avail(26);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      check_avail[board[i][j] - 'A'] = true;
    }
  }

  vector<char> initials;
  for (int i = 0; i < 26; ++i) {
    if (check_avail[i] == true) {
      initials.push_back('A' + i);
    }
  }

  vector<char> input;
  for (int i = 0; i < initials.size(); ++i) {
    input.push_back(initials[i]);
    for (int j = i; j < initials.size(); ++j) {
      // add initial only if different
      if (i != j) {
        input.push_back(initials[j]);
      }
      bool ok = is_victory(input);
      if (ok) {
        if (i == j) {
          ++one_team;
        } else {
          ++two_team;
        }
      }

      if (i != j) {
        input.pop_back();
      }
    }
    input.pop_back();
  }

  cout << one_team << "\n" << two_team << "\n";

  return 0;
}
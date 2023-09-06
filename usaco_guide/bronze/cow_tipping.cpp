// Cow Tipping
// http://www.usaco.org/index.php?page=viewproblem2&cpid=689

#include <bits/stdc++.h>

using namespace std;

bool arr[10][10];

void Flip(int x, int y) {
  for (int i = 0; i <= x; ++i) {
    for (int j = 0; j <= y; ++j) {
      arr[i][j] = !arr[i][j];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  for (int i = 0; i < N; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < N; ++j) {
      arr[i][j] = s[j] == '1' ? true : false;
    }
  }

  int ans = 0;
  while (true) {
    vector<pair<int, int>> frontier;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (arr[i][j] == false) continue;

        bool ok = true;
        for (int ii = i; ii < N; ++ii) {
          for (int jj = j; jj < N; ++jj) {
            if (ii == i && jj == j) continue;
            if (arr[ii][jj] == true) {
              ok = false;
            }
          }
        }

        if (ok == true) {
          frontier.emplace_back(i, j);
        }
      }
    }

    if (frontier.empty() == true) break;

    Flip(frontier.back().first, frontier.back().second);
    ans++;
  }

  cout << ans << "\n";

  return 0;
}
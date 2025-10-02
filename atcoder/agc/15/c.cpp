// C - Nuske vs Phantom Thnook (AGC)
// https://atcoder.jp/contests/agc015/tasks/agc015_c

#include <bits/stdc++.h>

using namespace std;

int n, m, q;

int ps[2005][2005];
int vps[2005][2005];
int hps[2005][2005];
char arr[2005][2005];


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> arr[i][j];
    }
  }
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (arr[i][j] == '1') {
        if (arr[i][j - 1] == '1' && arr[i - 1][j] == '1') {
          // merge into one
          ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] - 1;
        } else if (arr[i][j - 1] == '1' || arr[i - 1][j] == '1' ) {
          ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1];
        } else {
          // add new component
          ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1] + 1;
        }
      } else {
        ps[i][j] = ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1];
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      vps[i][j] = vps[i - 1][j];
      hps[i][j] = hps[i][j - 1];
      if (arr[i][j] == '1') {
        vps[i][j] += arr[i - 1][j] == '0';
        hps[i][j] += arr[i][j - 1] == '0';
      }
    }
  }

  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << (vps[x2][y1] - vps[x1][y1]) + (hps[x1][y2] - hps[x1][y1]) + (ps[x2][y2] - ps[x1][y2] - ps[x2][y1] + ps[x1][y1]) + (arr[x1][y1] == '1') << "\n";
  }

  return 0;
}
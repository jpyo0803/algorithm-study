// 색종이 붙이기 
// https://www.acmicpc.net/problem/17136

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int arr[10][10];
int p[5] = {5, 5, 5, 5, 5};

int ans = -1;

void Solve(int pos, int d) {
  if (pos == 100) {
    bool ok = true;
    for (int i = 0; i < 10 && ok; ++i) {
      for (int j = 0; j < 10; ++j) {
        if (arr[i][j] == 1) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      if (ans == -1 || d < ans) ans = d;
    } 
    return;
  }

  
  int x = pos / 10, y = pos % 10;
  if (arr[x][y] == 0) {
    Solve(pos + 1, d);
  } else {
    for (int t = 0; t < 5; ++t) { // type
      if (p[t] == 0) continue;
      if (x + t >= 10 || y + t >= 10) continue;

      bool ok = true;
      for (int i = x; i < x + t + 1 && ok; ++i) {
        for (int j = y; j < y + t + 1; ++j) {
          if (arr[i][j] != 1) {
            ok = false;
            break;
          } 
        }
      }

      if (ok) {
        p[t]--;
        for (int i = x; i < x + t + 1; ++i) {
          for (int j = y; j < y + t + 1; ++j) {
            arr[i][j] = 0;
          }
        }
        Solve(pos + 1, d + 1);
        for (int i = x; i < x + t + 1; ++i) {
          for (int j = y; j < y + t + 1; ++j) {
            arr[i][j] = 1;
          }
        }
        p[t]++;
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      cin >> arr[i][j];
    }
  }

  Solve(0, 0);
  cout << ans << "\n";

  return 0;
}
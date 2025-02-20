// 빗물
// https://www.acmicpc.net/problem/14719

#include <bits/stdc++.h>

using namespace std;

int h, w;

int arr[505][505];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> h >> w;
  for (int i = 0; i < w; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      arr[j][i] = -1;
    }
  }
  
  // from left to right
  for (int i = 0; i < h; ++i) {
    bool was_blockade = false;
    for (int j = 0; j < w; ++j) {
      if (arr[i][j] == -1) {
        was_blockade = true;
      } else {
        if (was_blockade == true) {
          arr[i][j]++;
        }
      }
    }
  }
  // from right to left
  int ans = 0;
  for (int i = 0; i < h; ++i) {
    bool was_blockade = false;
    for (int j = w - 1; j >= 0; --j) {
      if (arr[i][j] == -1) {
        was_blockade = true;
      } else {
        if (was_blockade == true) {
          if (arr[i][j] == 1) ans++;
        }
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
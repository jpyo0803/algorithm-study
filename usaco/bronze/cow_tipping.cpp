// Cow Tipping (Bronze)
// https://www.acmicpc.net/problem/14457

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10][10];

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

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char ch;
      cin >> ch;
      arr[i][j] = ch == '1';
    }
  }

  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (arr[i][j]) {
        ans++;
        Flip(i, j);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
// The Cow-Signal
// http://www.usaco.org/index.php?page=viewproblem2&cpid=665

#include <bits/stdc++.h>

using namespace std;

char arr[10][10];
int m, n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n >> k;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < m * k; ++i) {
    for (int j = 0; j < n * k; ++j) {
      cout << arr[i / k][j / k];
    }
    cout << "\n";
  }

  return 0;
}
// Spaced Out
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1088

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<vector<int>> arr(N, vector<int>(N));

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }

  int row_ans = 0;
  for (int i = 0; i < N; ++i) {
    int pse = 0, pso = 0;
    for (int j = 0; j < N; ++j) {
      if (j % 2 == 0)
        pse += arr[i][j];
      else
        pso += arr[i][j];
    }
    row_ans += max(pse, pso);
  }

  int col_ans = 0;
  for (int i = 0; i < N; ++i) {
    int pse = 0, pso = 0;
    for (int j = 0; j < N; ++j) {
      if (j % 2 == 0)
        pse += arr[j][i];
      else
        pso += arr[j][i];
    }
    col_ans += max(pse, pso);
  }

  cout << max(row_ans, col_ans) << "\n";

  return 0;
}
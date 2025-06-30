// Spaced Out (Silver)
// https://www.acmicpc.net/problem/20972

#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1005][1005];
int arr2[1005][1005];

int Solve(const vector<vector<int>>& v) {
  int ret = 0;
  for (int i = 0; i < n; ++i) {
    int sum1 = 0, sum2 = 0;
    for (int j = 0; j < n; ++j) {
      if (j % 2) sum2 += v[i][j];
      else sum1 += v[i][j];
    }
    ret += max(sum1, sum2);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  vector<vector<int>> vt(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> v[i][j];
      vt[j][i] = v[i][j];
    }
  }

  cout << max(Solve(v), Solve(vt)) << "\n";

  return 0;
}
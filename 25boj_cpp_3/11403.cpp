// 경로 찾기
// https://www.acmicpc.net/problem/11403

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;
int adj[105][105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> adj[i][j];
    }
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        adj[i][j] |= adj[i][k] && adj[k][j];
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << adj[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
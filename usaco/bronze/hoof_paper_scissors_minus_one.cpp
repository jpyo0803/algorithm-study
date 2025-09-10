// Hoof Paper Scissors Minus One (Bronze)
// https://www.acmicpc.net/problem/33769

#include <bits/stdc++.h>

#define ll long long

using namespace std;

char A[3005][3005];

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      cin >> A[i][j];
      if (j < i) {
        if (A[i][j] == 'D') A[j][i] = 'D';
        else A[j][i] = A[i][j] == 'W' ? 'L' : 'W';
      }
    }
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    int c = 0;
    for (int i = 1; i <= n; ++i) {
      if (A[i][a] == 'W' && A[i][b] == 'W') c++;
    }

    int d = n - c;
    int ans = c * c + c * d * 2;
    cout << ans << "\n";
  }

  return 0;
}
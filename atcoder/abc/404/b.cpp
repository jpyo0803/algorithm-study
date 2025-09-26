// B - Grid Rotation (ABC)
// https://atcoder.jp/contests/abc404/tasks/abc404_b

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

char s[105][105];
char t[105][105];
char tmp[105][105];

void Rotate90() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      tmp[j][n - 1 - i] = s[i][j];
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      s[i][j] = tmp[i][j];
    }
  }
}

int Diff() {
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (s[i][j] != t[i][j]) cnt++;
    }
  }
  return cnt;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> s[i][j];
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> t[i][j];
    }
  }

  int ans = Diff();
  for (int i = 0; i < 3; ++i) {
    Rotate90();
    ans = min(ans, Diff() + i + 1);
  }
  cout << ans << "\n";

  return 0;
}
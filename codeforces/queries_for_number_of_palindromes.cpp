// H. Queries for Number of Palindromes
// https://codeforces.com/contest/245/problem/H

#include <bits/stdc++.h>

#define ll long long

using namespace std;

string s;
int n;
int q;

int dp[5005][5005];
int ps[5005][5005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> s;
  n = s.length();
  
  for (int i = 1; i <= n + 1; ++i) {
    for (int j = 1; j <= i; ++j) {
      dp[i][j] = 1;
    }
  } 

  for (int j = 2; j <= n; ++j) {
    for (int i = 1; i <= n; ++i) {
      dp[i][j + i - 1] = dp[i + 1][j + i - 2] && s[i - 1] == s[j + i - 2];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      dp[i][j] = 0;
    }
  }

  for (int i = n; i >= 1; --i) {
    for (int j = 1; j <= n; ++j) {
      ps[i][j] = dp[i][j] + ps[i][j - 1] + ps[i + 1][j] - ps[i + 1][j - 1];
    }
  }

  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << ps[l][r]  << "\n";
  }

  return 0;
}
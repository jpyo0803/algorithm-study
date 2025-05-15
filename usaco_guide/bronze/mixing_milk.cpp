// Mixing Milk (Bronze)
// https://www.acmicpc.net/problem/16769

#include <bits/stdc++.h>

using namespace std;

// 1 <= c,m <= 1e9
int c[3];
int m[3];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 0; i < 3; ++i) cin >> c[i] >> m[i];

  for (int i = 0; i < 100; ++i) {
    int a = i % 3, b = (i + 1) % 3;
    int amt = min(m[a], c[b] - m[b]);
    m[a] -= amt;
    m[b] += amt;
  }

  for (int i = 0; i < 3; ++i) cout << m[i] << "\n";

  return 0;
}
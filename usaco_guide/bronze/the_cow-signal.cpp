// The Cow-Signal (Bronze)
// https://www.acmicpc.net/problem/14175

#include <bits/stdc++.h>

using namespace std;

int m, n, k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> m >> n >> k;

  for (int i = 0; i < m; ++i) {
    string line;
    cin >> line;
    for (int k1 = 0; k1 < k; ++k1) {
      for (int j = 0; j < n; ++j) {
        for (int k2 = 0; k2 < k; ++k2) {
          cout << line[j];
        }
      }
      cout << "\n";
    }
  }

  return 0;
}
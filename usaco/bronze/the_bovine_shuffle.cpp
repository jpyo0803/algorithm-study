// The Bovine Shuffle (Bronze)
// https://www.acmicpc.net/problem/15464

#include <bits/stdc++.h>

using namespace std;

int n;
int ord[105];
string tag[105];
int buf[2][105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ord[x - 1] = i;
  }
  for (int i = 0; i < n; ++i) cin >> tag[i];

  for (int i = 0; i < n; ++i) buf[0][i] = i;

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      buf[(i + 1) % 2][ord[j]] = buf[i % 2][j];
    }
  }

  for (int i = 0; i < n; ++i) cout << tag[buf[1][i]] << "\n";

  return 0;
}
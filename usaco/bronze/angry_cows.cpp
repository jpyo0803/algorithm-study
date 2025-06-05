// Angry Cows (Bronze)
// https://www.acmicpc.net/problem/11977

#include <bits/stdc++.h>

using namespace std;

int n;
int candidate[105];
int cows[105];

int SolveRight(int c) {
  int ret = 0;
  bool ok = true;
  int t = 1;
  while (ok) {
    ok = false;
    int i = c;
    while (i + 1 < n && cows[i + 1] <= cows[c] + t) {
      ok = true;
      ret++;
      i++;
    }
    c = i;
    t++;
  }
  return ret;
}

int SolveLeft(int c) {
  int ret = 0;
  bool ok = true;
  int t = 1;
  while (ok) {
    ok = false;
    int i = c;
    while (i - 1 >= 0 && cows[c] - t <= cows[i - 1]) {
      ok = true;
      ret++;
      i--;
    }
    c = i;
    t++;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> cows[i];

  sort(cows, cows + n);

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, SolveLeft(i) + SolveRight(i) + 1);
  }

  cout << ans << "\n";

  return 0;
}
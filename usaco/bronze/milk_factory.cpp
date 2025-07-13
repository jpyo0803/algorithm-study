// Milk Factory (Bronze)
// https://www.acmicpc.net/problem/17199

#include <bits/stdc++.h>

using namespace std;

int n;

int in_deg[105];
int out_deg[105];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    out_deg[a]++;
    in_deg[b]++;
  }

  int ans = -1;

  for (int i = 1; i <=  n; ++i) {
    if (out_deg[i] == 0 && in_deg[i] > 0) {
      if (ans == -1) {
        ans = i;
      } else {
        ans = -1;
        break;
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
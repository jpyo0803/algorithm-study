// The Bucket List (Bronze)
// https://www.acmicpc.net/problem/16770

#include <bits/stdc++.h>

using namespace std;

int n;

int delta[1005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);


  cin >> n;

  for (int i = 0; i < n; ++i) {
    int s, t, b;
    cin >> s >> t >> b;
    delta[s] += b;
    delta[t] -= b;
  }

  int ans = 0;

  int sum = 0;

  for (int i = 1; i <= 1e3; ++i) {
    sum += delta[i];
    ans = max(ans, sum);
  } 

  cout << ans << "\n";

  return 0;
}
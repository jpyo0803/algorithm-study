// 쿨한 물건 구매
// https://www.acmicpc.net/problem/1214

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int D, P, Q;
  cin >> D >> P >> Q;

  if (Q > P) swap(P, Q);
  // P > Q

  int j = (D + P - 1) / P;
  int ans = P * j;

  int L = min((D + P - 1) / P, Q);
  for (int i = 0; i < L; ++i) {
    j = (D - P * i + Q - 1) / Q;
    int C = P * i + Q * j;
    ans = min(ans, C);
  }

  cout << ans << "\n";

  return 0;
}
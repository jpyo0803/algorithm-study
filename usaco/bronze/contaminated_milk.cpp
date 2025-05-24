// Contaminated Milk (Bronze)
// https://www.acmicpc.net/problem/11972

#include <bits/stdc++.h>

using namespace std;

int N, M, D, S;
/*
   N = # people, 1 <= N <= 50
   M = # different milks, 1 <= M <= 50
   D = # drink, 1 <= D <= 1000
   S = # Sick, 1 <= S <= N
   한 사람은 최대 한번만 아플 수 있고, 아픈 시점 전에 먹었던 우유에
   의해서만 아플 수 있음

   Problem: 어떤 우유(정확히 1개)가 상했을까?
   각 우유를 상했다고 가정하고 주어진 정보가 consistent한지 검사?
   만약 consistent하다면 최대치를 구할수있는 후보
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> N >> M >> D >> S;

  vector<tuple<int, int, int>> dv(D);
  for (int i = 0; i < D; ++i) {
    cin >> get<0>(dv[i]) >> get<1>(dv[i]) >> get<2>(dv[i]);
  }

  vector<pair<int, int>> sv(S);
  for (int i = 0; i < S; ++i) {
    cin >> sv[i].first >> sv[i].second;
  }

  int ans = 0;
  for (int i = 1; i <= M; ++i) {
    vector<int> pdtv(
        N + 1, 1e9);  // keep the earliest time when people drink target milk
    for (auto [p, m, t] : dv) {  // 50 * 1000
      if (m != i) continue;
      if (t < pdtv[p]) {
        pdtv[p] = t;
      }
    }

    bool ok = true;
    for (auto [p, t] : sv) {
      if (t <= pdtv[p]) {
        // inconsistent, even if pdtv[p] == 1e9, it is still true as that person
        // never the drank but got sick clearly that drink is not the cause of
        // sick, so not ok
        ok = false;
      }
    }
    if (ok) {
      int cand = 0;
      // how many people actually drank?
      for (auto e : pdtv) {
        if (e != 1e9) {
          cand++;
        }
      }
      ans = max(ans, cand);
    }
  }

  cout << ans << "\n";

  return 0;
}
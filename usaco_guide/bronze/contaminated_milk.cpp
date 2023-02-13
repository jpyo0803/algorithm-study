// Contaminated Milk
// http://www.usaco.org/index.php?page=viewproblem2&cpid=569

#include <bits/stdc++.h>

using namespace std;

struct Info {
  int p, m, t;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, D, S;
  cin >> N >> M >> D >> S;

  vector<Info> v(D);
  for (int i = 0; i < D; ++i) {
    cin >> v[i].p >> v[i].m >> v[i].t;
  }

  // Compute possible candidates for the bad milk
  bool first = true;
  bool intersect[51]{};  // since M <= 50
  for (int i = 0; i < S; ++i) {
    int p, t;
    cin >> p >> t;

    bool cand[51]{};
    for (int j = 0; j < D; ++j) {
      if (v[j].p != p) continue;
      if (v[j].t >= t) continue;
      cand[v[j].m] = true;
    }

    if (first) {
      for (int j = 1; j <= M; ++j) {
        intersect[j] = cand[j];
      }
      first = false;
    } else {
      for (int j = 1; j <= M; ++j) {
        intersect[j] &= cand[j];
      }
    }
  }

  // Assume each candidate as the bad one and compute possible number of the
  // sick
  int ans = 0;
  for (int i = 1; i <= M; ++i) {
    if (intersect[i] == false) continue;

    bool who_drank[51]{};
    for (int j = 0; j < D; ++j) {
      if (v[j].m == i) {
        who_drank[v[j].p] = true;
      }
    }
    int cnt = 0;
    for (int j = 1; j <= N; ++j) {
      if (who_drank[j]) ++cnt;
    }
    ans = max(ans, cnt);
  }

  cout << ans << "\n";

  return 0;
}
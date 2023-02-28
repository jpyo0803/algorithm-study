// Air Cownditioning II (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1276

#include <bits/stdc++.h>

using namespace std;

struct Cow {
  int s, t, c;

  Cow() = default;
};

struct AC {
  int a, b, p, m;

  AC() = default;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<Cow> cows(N);
  for (int i = 0; i < N; ++i) {
    cin >> cows[i].s >> cows[i].t >> cows[i].c;
  }

  vector<AC> acs(M);
  for (int i = 0; i < M; ++i) {
    cin >> acs[i].a >> acs[i].b >> acs[i].p >> acs[i].m;
  }

  int ans = 1e9;
  for (int i = 0; i < (1 << M); ++i) {  // O(2^10) = 1024
    int cool[101]{};
    int cost = 0;
    for (int j = 0; j < M; ++j) {  // O(10), 10240
      if (i & (1 << j)) {
        for (int k = acs[j].a; k <= acs[j].b; ++k) { // 1024000
          cool[k] -= acs[j].p;
        }
        cost += acs[j].m;
      }
    }

    bool ok = true;
    for (int j = 0; j < N; ++j) { // 20000
      for (int k = cows[j].s; k <= cows[j].t; ++k) { // 2000000
        if (cool[k] + cows[j].c > 0) {
          ok = false;
        }
      }
      if (!ok) break;
    }

    if (ok) {
      ans = min(ans, cost);
    }
  }

  cout << ans << "\n";

  return 0;
}
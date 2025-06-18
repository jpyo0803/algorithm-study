// Into Blocks (easy version)
// https://codeforces.com/contest/1209/problem/G1

#include <bits/stdc++.h>

using namespace std;

int n, q;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> q; // q == 0
  assert(q == 0);

  map<int, vector<int>> mmm;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mmm[x].push_back(i);
  }

  vector<tuple<int, int, int>> vv;
  for (const auto& e : mmm) {
    tuple<int, int ,int> t{e.second[0], e.second.back(), e.second.size()};
    vv.push_back(t);
  }

  sort(vv.begin(), vv.end());

  int ans = 0;

  int s, e, mf;
  tie(s, e, mf) = vv[0];

  for (int i = 1; i < vv.size(); ++i) {
    int s2, e2, f;
    tie(s2, e2, f) = vv[i];
    if (e < s2) {
      ans +=  e - s + 1 - mf;
      s = s2;
      e = e2;
      mf = f;
    } else {
      e = max(e, e2);
      mf = max(mf, f);
    }
  }
  ans +=  e - s + 1 - mf;

  cout << ans << "\n";

  return 0;
}
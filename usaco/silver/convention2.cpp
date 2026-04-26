// Convention II (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=859

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ifstream fin("convention2.in");
  ofstream fout("convention2.out");

  int n;
  fin >> n;
  vector<tuple<int, int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    fin >> get<0>(v[i]) >> get<2>(v[i]);
    get<1>(v[i]) = n - i; // seniority
  }

  sort(v.begin(), v.end());

  int lft = get<0>(v[0]) + get<2>(v[0]); // last finish time
  int ans = 0;

  priority_queue<tuple<int, int, int>> pq; // seniority, a, t
  int i = 1;
  while (true) {
    while (i < n && get<0>(v[i]) <= lft) {
      int a, s, t;
      tie(a, s, t) = v[i++];
      pq.emplace(s, a, t);
    }

    if (pq.empty()) {
      if (i == n) break;

      int a, s, t;
      tie(a, s, t) = v[i++];
      pq.emplace(s, a, t);
    }

    int s, a, t;
    tie(s, a, t) = pq.top();
    pq.pop();

    int st = max(lft, a);
    ans = max(ans, st - a);
    lft = st + t;
  }
  fout << ans << "\n";

  return 0;
}
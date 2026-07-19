// Deforestation (Silver)
// https://usaco.org/index.php?page=viewproblem2&cpid=1447

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  // ifstream fin("input_file.in");
  // ofstream fout("output_file.out");

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> tv(n);
    for (auto& e : tv) cin >> e;
    sort(tv.begin(), tv.end());

    vector<tuple<int, int, int>> rv(k);
    for (auto& e : rv) {
      int l, r, x;
      cin >> l >> r >> x;
      get<0>(e) = l;
      get<1>(e) = r;
      
      auto lit = lower_bound(tv.begin(), tv.end(), l);
      auto rit = upper_bound(tv.begin(), tv.end(), r);
      int p = rit - lit;
      get<2>(e) = p - x;
    }

    vector<tuple<int, int, int, int>> av;
    for (auto e : tv) {
      av.emplace_back(e, 1, -1, -1);
    }
    for (auto e : rv) {
      int l, r, cut;
      tie(l, r, cut) = e;
      av.emplace_back(l, 0, r, cut);
    }

    sort(av.begin(), av.end());
    priority_queue<pair<int, int>> pq; // constraint, r

    int ans = 0;
    for (auto e : av) {
      int pos, type, r, cut;
      tie(pos, type, r, cut) = e;
      if (type == 0) { // range
        pq.emplace(-(ans + cut), r);
      } else {
        while (pq.size() && pq.top().second < pos) pq.pop();
        if (pq.empty()) ans++;
        else {
          if (-pq.top().first > ans) ans++;
        }
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
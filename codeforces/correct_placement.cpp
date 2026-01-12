// Correct Placement
// https://codeforces.com/problemset/problem/1472/E

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> vv;
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      vv.emplace_back(min(a, b), max(a, b), i);
    }

    sort(vv.begin(), vv.end(),
         [](tuple<int, int, int> x, tuple<int, int, int> y) {
           if (get<0>(x) == get<0>(y)) {
             return get<1>(x) < get<1>(y);
           }
           return get<0>(x) < get<0>(y);
         });

    vector<int> ans(n);

    set<pair<int, int>> ss;
    vector<pair<int, int>> pv;
    int last_x = -1;

    for (auto [x, y, id] : vv) {
      if (last_x != x) {
        for (auto e : pv) {
          ss.insert(e);
        }
        pv.clear();
        last_x = x;
      }
      int j = -1;
      if (ss.size() && ss.begin()->first < y) {
        j = ss.begin()->second + 1;
      }

      ans[id] = j;
      pv.emplace_back(y, id);
    }

    for (auto e : ans) {
      cout << e << " ";
    }
    cout << "\n";
  }

  return 0;
}
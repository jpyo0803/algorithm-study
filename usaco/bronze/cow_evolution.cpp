// Cow Evolution (Bronze)
// https://www.acmicpc.net/problem/17200

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  map<string, set<int>> mv;
  for (int i = 0; i < n; ++i) {
    int k;
    cin >> k;
    while (k--) {
      string s; // feature
      cin >> s;
      mv[s].insert(i);
    }
  }

  bool ok = true;
  for (auto& x : mv) {
    for (auto& y : mv) {
      if (x.first == y.first) continue;
      int inter_cnt = 0;
      for (auto e : x.second) {
        if (y.second.find(e) != y.second.end()) {
          inter_cnt++;
        }
      }

      if (inter_cnt > 0 && x.second.size() > inter_cnt && y.second.size() > inter_cnt) {
        ok = false;
      }
    }
  }

  cout << (ok ? "yes" : "no") << "\n";

  return 0;
}
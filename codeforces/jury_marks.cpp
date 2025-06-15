// Jury Marks
// https://codeforces.com/contest/831/problem/C

#include <bits/stdc++.h>

using namespace std;

int n, k;
int ps[2005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> k >> n;
  for (int i = 1; i <= k; ++i) {
    int x;
    cin >> x;
    ps[i] = ps[i - 1] + x;
  }

  set<int> bs;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    bs.insert(x);
  }
  
  vector<int> cands;
  for (int i = 1; i <= k; ++i) {
    cands.push_back(*bs.begin() - ps[i]);
  }

  cands.erase(unique(cands.begin(), cands.end()), cands.end());

  int ans = 0;
  for (auto cand : cands) {
    set<int> ss;
    for (int i = 1; i <= k; ++i) {
      int x = cand + ps[i];
      if (bs.find(x) != bs.end()) {
        ss.insert(x);
      }
    }
    if (ss.size() == bs.size()) ans++;
  }

  cout << ans << "\n";

  return 0;
}
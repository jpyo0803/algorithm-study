// E. Packmen
// https://codeforces.com/contest/847/problem/E

#include <bits/stdc++.h>

#define ll long long

using namespace std;


ll Solve(const vector<int>& apos, const vector<int>& ppos) {
  ll lo = 1, hi = 1e10;

  while (lo < hi) {
    ll x = lo + (hi - lo) / 2;

    bool ok = true;
    int i = 0;
    // cout << "x: " << x << endl;
    for (auto p : ppos) {
      int j = i;
      ll l = max(0, p - apos[i]);
      ll r = max(0, apos[j] - p);
      ll d = min(l, r) + l + r;
      while (d <= x) {
        if (j + 1 == apos.size()) break;
        ll l = max(0, p - apos[i]);
        ll r = max(0, apos[j + 1] - p);
        d = min(l, r) + l + r;
        j++;
      }
      if (d > x) j--;
      i = j + 1;
      if (i == apos.size()) break;
    }

    if (i != apos.size()) ok = false;
    
    if (ok) {
      hi = x;
    } else {
      lo = x + 1;
    }
  }
  return hi;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  vector<int> apos, ppos;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') apos.push_back(i);
    else if (s[i] == 'P') ppos.push_back(i);
  }

  ll ans = Solve(apos, ppos);

  cout << ans << "\n";  

  return 0;
}
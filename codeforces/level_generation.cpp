// F. Level Generation
// https://codeforces.com/problemset/problem/818/F

#include <bits/stdc++.h>
 
#define ll long long
 
using namespace std;

ll q, n;

ll F2(ll x) {
  ll y = n - x;
  return y + min(x * (x - 1) / 2, y);
}

ll Solve() {  
  ll lo = 1, hi = n;
 
  ll ans = 0;
  while (lo <= hi) {
    ll x1 = lo + (hi - lo) / 3;
    ll x2 = hi - (hi - lo) / 3;

    ll y1 = F2(x1);
    ll y2 = F2(x2);

    ans = max({ans, y1, y2});

    if (y1 == y2) {
      lo = x1 + 1;
      hi = x2 - 1;
    } else if (y1 < y2) {
      lo = x1 + 1;
    } else {
      hi = x2 - 1;
    }
  }

  return ans;
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
 
  cin >> q;
 
  while (q--) {
    cin >> n;
    cout << Solve() << "\n";
  }
 
  return 0;
}
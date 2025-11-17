// Ammar-utiful Array
// https://codeforces.com/gym/104468/problem/H

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, q;
int a[200005];
int c[200005];

ll total_up = 0;
ll my_down[200005];

vector<ll> ps[200005];

int Solve(int col, ll y) {
  const auto& v = ps[col];

  int lo = -1, hi  = v.size() - 1;
  while (lo < hi) {
    int mid = lo + 1 + (hi - (lo + 1)) / 2;
    if (v[mid] + (total_up + my_down[col]) * (mid + 1) > y) {
      hi = mid - 1;
    } else {
      lo = mid;
    }
  }
  return lo + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i]; 
  for (int i = 0; i < n; ++i) cin >> c[i]; 

  for (int i = 0; i < n; ++i) {
    ps[c[i]].push_back(a[i]);
  }

  for (int i = 1; i <= 200000; ++i) {
    for (int j = 0; j < ps[i].size(); ++j) {
      if (j == 0) continue;
      ps[i][j] += ps[i][j - 1];
    }
  }

  cin >> q;
  while (q--) {
    int cmd, col;
    cin >> cmd >> col;
    if (cmd == 1) {
      int x;
      cin >> x;
      total_up += x;
      my_down[col] -= x;
    } else {
      ll y;
      cin >> y;

      cout << Solve(col, y) << "\n";
    }
  }

  return 0;
}
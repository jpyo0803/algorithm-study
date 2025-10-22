// Counting Haybales (Silver)
// https://www.acmicpc.net/problem/14170

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int UpperBound(const vector<int>& v, int n, int x) {
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;
    if (v[m] <= x) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for (auto& e : a) cin >> e;
  sort(a.begin(), a.end());

  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << UpperBound(a, n, y) - UpperBound(a, n, x - 1) << "\n";
  }

  return 0;
}
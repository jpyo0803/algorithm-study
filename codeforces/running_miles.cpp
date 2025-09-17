// D. Running Miles
// https://codeforces.com/contest/1826/problem/D

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<int> b(n);
    for (int i = 0; i < n; ++i) cin >> b[i];

    vector<int> lps(n + 5, -1e9);
    vector<int> rps(n + 5, -1e9);

    pair<int, int> x = {-1, -1}; // val, pos
    for (int i = 0; i < n; ++i) {
      if (x.first == -1) {
        x = {b[i], i};
      } else {
        if ((x.first - (i - x.second)) < b[i]) {
          x = {b[i], i};
        }
      }
      lps[i] = x.first - (i - x.second) - 1;
    }   
    x = {-1, -1}; 
    for (int i = n - 1; i >= 0; --i) {
      if (x.first == -1) {
        x = {b[i], i};
      } else {
        if ((x.first - (x.second - i)) < b[i]) {
          x = {b[i], i};
        }
      }
      rps[i] = x.first - (x.second - i) - 1;
    }

    int ans = -1e9;
    for (int i = 1; i < n - 1; ++i) {
      ans = max(ans, b[i] + lps[i - 1] + rps[i + 1]);
    }
    cout << ans << "\n";
  }

  return 0;
}
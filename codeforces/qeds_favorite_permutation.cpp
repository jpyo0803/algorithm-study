// D. QED's Favorite Permutation
// https://codeforces.com/contest/2030/problem/D

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
    int n, q;
    string s;

    cin >> n >> q;

    vector<int> ps(n + 5, 0);

    for (int i = 1; i <= n; ++i) {
      int p;
      cin >> p;
      int a = min(i, p);
      int b = max(i, p);
      if (a == b) continue;
      ps[a]++, ps[b]--;
    }
    for (int i = 1; i <= n; ++i) ps[i] += ps[i - 1];
    // for (int i = 1; i <= n; ++i) cout << ps[i] << " ";
    // cout << endl;
    cin >> s;

    set<int> blk;
    for (int i = 0; i < s.length() - 1; ++i) {
      if (s[i] == 'L' && s[i + 1] == 'R') {
        if (ps[i + 1] > 0) {
          blk.insert(i + 1);
        }
      }
    }
    // for (auto e : blk) cout << e << endl;
    // return 0;

    while (q--) {
      int x;
      cin >> x;
      x--;
      
      if (x < n - 1) {
        if (s[x] == 'L' && s[x + 1] == 'R') {
          if (ps[x + 1] > 0) {
            blk.erase(x + 1);
          }
        }
      }
      if (x > 0) {
        if (s[x - 1] == 'L' && s[x] == 'R') {
          if (ps[x] > 0) {
            blk.erase(x);
          }
        }
      }

      s[x] = s[x] == 'R' ? 'L' : 'R';

      if (x < n - 1) {
        if (s[x] == 'L' && s[x + 1] == 'R') {
          if (ps[x + 1] > 0) {
            blk.insert(x + 1);
          }
        }
      }
      if (x > 0) {
        if (s[x - 1] == 'L' && s[x] == 'R') {
          if (ps[x] > 0) {
            blk.insert(x);
          }
        }
      }
      // cout << "size: " << blk.size() << endl;

      if (blk.size() == 0) cout << "YES\n";
      else cout << "NO\n";
    }
  }

  return 0;
}
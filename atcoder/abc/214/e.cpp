// E - Packing Under Range Regulations (ABC)
// https://atcoder.jp/contests/abc214/tasks/abc214_e

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
    vector<pair<int, int>> rv(n);
    for (int i = 0; i < n; ++i) cin >> rv[i].first >> rv[i].second;
    sort(rv.begin(), rv.end());

    bool ok = true;
    
    int i = 1;
    int j = 0;
    priority_queue<int> pq;
    while (i <= 1e9) {
      while (j < n && rv[j].first == i) {
        pq.push(-rv[j].second);
        j++;
      }

      if (pq.size()) {
        if (-pq.top() < i) {
          ok = false;
          break;
        }
        pq.pop();
        i++;
      } else {
        if (j < n) {
          i = rv[j].first;
        } else {
          break;
        }
      }
    }
    if (pq.size()) ok = false;

    cout << (ok ? "Yes" : "No") << "\n";
  }

  return 0;
}
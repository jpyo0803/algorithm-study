// Serval and Kaitenzushi Buffet
// https://codeforces.com/contest/2085/problem/D

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
    int n, k;
    cin >> n >> k;

    int q = n / (k + 1);
    int c = n - q * (k + 1);
    priority_queue<int> pq;

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      int d;
      cin >> d;
      pq.push(d);
      if (i == c) {
        ans += pq.top();
        pq.pop();
        c += (k + 1);
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
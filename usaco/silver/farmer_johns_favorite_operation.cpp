// Farmer John's Favorite Operation (Silver)
// https://www.acmicpc.net/problem/33505

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
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      a[i] %= m;
    } 
      
    sort(a.begin(), a.end());

    for (int i = 0; i < n - 1; ++i) a.push_back(a[i] + m);
    int l1 = 0, r1 = (n - 1) / 2, l2 = n / 2, r2 = n - 1;
    ll lsum = 0, rsum = 0;   
    for (int i = l1; i <= r1; ++i) lsum += a[i]; 
    for (int i = l2; i <= r2; ++i) rsum += a[i]; 

    ll ans = rsum - lsum;
    for (int i = 0; i < n - 1; ++i) {
      lsum -= a[l1++];
      lsum += a[++r1];
      rsum -= a[l2++];
      rsum += a[++r2];
      ans = min(ans, rsum - lsum);
    }
    cout << ans << "\n";
  }

  return 0;
}
// Books
// https://codeforces.com/contest/279/problem/B

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, t;
int arr[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> t;

  for (int i = 0; i < n; ++i) cin >> arr[i];
  
  int ans = 0;
  int sum = 0;
  int l = 0, r = -1;
  while (r + 1 < n) {
    if (sum + arr[r + 1] <= t) {
      sum += arr[++r];
      ans = max(ans, r - l + 1);
    } else {
      sum -= arr[l++];
    }
  }
  cout << ans << "\n";

  return 0;
}
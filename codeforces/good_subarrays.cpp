// C. Good Subarrays
// https://codeforces.com/contest/1398/problem/C

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
    string s;
    cin >> s;

    map<int, int> cnt;
    cnt.insert({0, 1});
    int sum = 0;
    ll ans = 0;
    for (int i = 0; i < s.length(); ++i) {
      sum += s[i] - '0';
      int d = sum - (i + 1);
      ans += cnt[d];
      cnt[d]++;
    }
    cout << ans << "\n";
  }

  return 0;
}
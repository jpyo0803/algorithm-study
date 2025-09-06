// Subsequences Summing to Sevens (Silver)
// https://www.acmicpc.net/problem/11974

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int l[6];
int r[6];

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < 7; ++i) l[i] = -1;

  long long sum = 0;
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
    int rem = sum % 7;
    if (rem == 0) {
      ans = max(ans, i + 1);
    } else {
      if (l[rem] == -1) l[rem] = i;
      r[rem] = i;
      if (l[rem] != -1) {
        ans = max(ans, r[rem] - l[rem]);
      }
    }
  }
  cout << ans << "\n";

  return 0;
}
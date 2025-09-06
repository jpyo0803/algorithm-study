// Hoof, Paper, Scissors (Silver)
// https://www.acmicpc.net/problem/14453

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

int h[100005];
int p[100005];
int s[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    char x;
    cin >> x;
    if (x == 'H') h[i + 1]++;
    else if (x == 'P') p[i + 1]++;
    else s[i + 1]++;

    h[i + 1] += h[i];
    p[i + 1] += p[i];
    s[i + 1] += s[i];
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = max(ans, h[i] + h[n] - h[i]);
    ans = max(ans, h[i] + p[n] - p[i]);
    ans = max(ans, h[i] + s[n] - s[i]);

    ans = max(ans, p[i] + h[n] - h[i]);
    ans = max(ans, p[i] + p[n] - p[i]);
    ans = max(ans, p[i] + s[n] - s[i]);

    ans = max(ans, s[i] + h[n] - h[i]);
    ans = max(ans, s[i] + p[n] - p[i]);
    ans = max(ans, s[i] + s[n] - s[i]);
  }
  cout << ans << "\n";

  return 0;
}
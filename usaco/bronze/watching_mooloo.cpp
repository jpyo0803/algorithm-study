// Watching Mooloo (Bronze)
// https://www.acmicpc.net/problem/

#include <bits/stdc++.h>

using namespace std;

long long n;
int k;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;

  long long last_d = -1e15;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    long long d;
    cin >> d;
    long long c = d - last_d;
    if (c < k + 1) ans += c;
    else ans += k + 1;
    last_d = d;
  }

  cout << ans << "\n";

  return 0;
}
// Milk Measurement (Bronze)
// https://www.acmicpc.net/problem/15465

#include <bits/stdc++.h>

using namespace std;

int n;
int b, e, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  b = e = m = 7;
  cin >> n;
  vector<tuple<int, string, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]);
  }

  sort(v.begin(), v.end());

  int ans = 0;
  string prev = "bem";
  for (auto x : v) {
    string now;

    int day, delta;
    string who;
    tie(day, who, delta) = x;

    if (who[0] == 'B')
      b += delta;
    else if (who[0] == 'E')
      e += delta;
    else
      m += delta;

    int maxx = max(b, max(e, m));

    if (b == maxx) now.push_back('b');
    if (e == maxx) now.push_back('e');
    if (m == maxx) now.push_back('m');

    if (now != prev) ans++;

    prev = now;
  }

  cout << ans << "\n";

  return 0;
}
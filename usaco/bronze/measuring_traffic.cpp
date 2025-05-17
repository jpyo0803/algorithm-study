// Measuring Traffic (Bronze)
// https://www.acmicpc.net/problem/17041

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<tuple<string, int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(v[i]) >> get<1>(v[i]) >>get<2>(v[i]);
  }

  int low = -1, high;

  for (int i = n - 1; i >= 0; --i) {
    string t;
    int a, b;
    tie(t, a, b) = v[i];
    
    if (t == "none") {
      if (low == -1) {
        low = a;
        high = b;
      } else {
        low = max(low, a);
        high = min(high, b);
      }
    } else if (t == "off") {
      if (low == -1) continue;
      low += a;
      high += b;
    } else { // on
      if (low == -1) continue;
      low = max(0, low - b);
      high = max(0, high - a);

    }
  }

  cout << low << " " << high << "\n";

  low = -1;
  for (auto e : v) {
    string t;
    int a, b;
    tie(t, a, b) = e;
    
    if (t == "none") {
      if (low == -1) {
        low = a;
        high = b;
      } else {
        low = max(low, a);
        high = min(high, b);
      }
    } else if (t == "on") {
      if (low == -1) continue;
      low += a;
      high += b;
    } else { // off
      if (low == -1) continue;
      low = max(0, low - b);
      high = max(0, high - a);
    }
  }

  cout << low << " " << high << "\n";

  return 0;
}
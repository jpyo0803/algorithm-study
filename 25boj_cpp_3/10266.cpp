// 시계 사진들
// https://www.acmicpc.net/problem/10266

#include <bits/stdc++.h>

using namespace std;

int n;

int ft[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  vector<int> a, b;
  for (int i = 0; i < n; ++i) {
    int diff = v[(i + 1) % n] - v[i];
    if (diff < 0) diff += 360000;
    a.push_back(diff);
  }
  for (int i = 0; i < n; ++i) a.push_back(a[i]);  // concatenate to itself

  for (int i = 0; i < n; ++i) cin >> v[i];
  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) {
    int diff = v[(i + 1) % n] - v[i];
    if (diff < 0) diff += 360000;
    b.push_back(diff);
  }

  // a is haystack, b is needle

  // compute failure table
  int i = 1, m = 0;

  while (i + m < n) {
    if (b[m] == b[i + m]) {
      ft[i + m] = m + 1;
      m++;
    } else {
      if (m == 0) {
        i++;
      } else {
        i += m - ft[m - 1];
        m = ft[m - 1];
      }
    }
  }

  i = 0, m = 0;
  bool ok = false;
  while (i + m < 2 * n) {
    // i + m < 2 * n
    // m == n -> match found
    if (a[i + m] == b[m]) {
      m++;
      if (m == n) {
        ok = true;
        i += m - ft[m - 1];
        m = ft[m - 1];
        break;
      }
    } else {
      if (m == 0) {
        i++;
      } else {
        i += m - ft[m - 1];
        m = ft[m - 1];
      }
    }
  }

  if (ok) cout << "possible\n";
  else cout << "impossible\n";

  return 0;
}
// Taming the Herd (Bronze)
// https://www.acmicpc.net/problem/15753

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (a[0] >= 1) {
    cout << "-1\n";
    return 0;
  }
  a[0] = 0;

  int min_ans = 0, max_ans = 0;
  int cnt = -1;

  for (int i = n - 1; i >= 0; --i) {
    // if cnt >= 0, then it must match a[i] unless a[i] == -1
    if (a[i] == -1) {
      if (cnt != -1) {
        a[i] = cnt;
      } else {
        max_ans++;
      }
    } else {
      if (cnt != -1) {
        if (a[i] != cnt) {
          cout << "-1\n";
          return 0;
        }
      } else {
        cnt = a[i];
      }
    }

    if (a[i] == 0) {  // if 0, must increase
      min_ans++, max_ans++;
    }
    if (cnt >= 0) --cnt;
  }

  cout << min_ans << " " << max_ans << "\n";

  return 0;
}
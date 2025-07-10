// Race (Bronze)
// https://www.acmicpc.net/problem/18324

#include <bits/stdc++.h>

using namespace std;

int k, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> k >> n;
  while (n--) {
    int x;
    cin >> x;

    int dist = 0;
    int t = 0;
    for (int s = 1;; s++) {
      dist += s;
      t++;
      if (dist >= k) break;
      if (s >= x) {
        dist += s;
        t++;
        if (dist >= k) break;
      }
    }
    cout << t << "\n";
  }

  return 0;
}
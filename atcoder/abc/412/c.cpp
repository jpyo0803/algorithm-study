// C - Giant Domino (ABC)
// https://atcoder.jp/contests/abc412/tasks/abc412_c

#include <bits/stdc++.h>

using namespace std;

int t, n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> n;
    int curr, last;
    cin >> curr;

    priority_queue<int> pq;
    for (int i = 0; i < n - 2; ++i) {
      int x;
      cin >> x;
      pq.push(-x);
    }
    cin >> last;

    int ans = 0;
    while (curr * 2 < last && pq.size()) {
      int cand = -1;
      while (pq.size()) {
        int x = -pq.top();
        if (curr * 2 >= x) {
          cand = x;
          pq.pop();
        } else {
          break;
        }
      }
      if (cand == -1) break;
      curr = cand;
      ans++;
    }
    if (curr * 2 >= last) {
      cout << ans + 2 << "\n";
    } else {
      cout << "-1\n";
    }
  }  
  
  return 0;
}
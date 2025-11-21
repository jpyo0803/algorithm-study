// 이중 우선순위 큐
// https://www.acmicpc.net/problem/7662

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    priority_queue<ll> max_pq, min_pq;
    map<ll, int> max_ignore, min_ignore;
    for (int i = 0; i < n; ++i) {
      char a;
      ll b;
      cin >> a >> b;

      if (a == 'I') {
        max_pq.push(b);
        min_pq.push(-b);
      } else {
        if (b == -1) {
          while (min_pq.size()) {
            auto e = -min_pq.top();
            min_pq.pop();
            if (min_ignore[e] > 0) {
              min_ignore[e]--;
            } else {
              max_ignore[e]++;
              break;
            }
          }
        } else {
          while (max_pq.size()) {
            auto e = max_pq.top();
            max_pq.pop();
            if (max_ignore[e] > 0) {
              max_ignore[e]--;
            } else {
              min_ignore[e]++;
              break;
            }
          }
        }
      }
    }

    while (max_pq.size() && max_ignore[max_pq.top()] > 0) {
      max_ignore[max_pq.top()]--;
      max_pq.pop();
    }
    while (min_pq.size() && min_ignore[-min_pq.top()] > 0) {
      min_ignore[-min_pq.top()]--;
      min_pq.pop();
    }

    if (max_pq.empty() || min_pq.empty()) cout << "EMPTY\n";
    else cout << max_pq.top() << " " << -min_pq.top() << "\n";
  }

  return 0;
}
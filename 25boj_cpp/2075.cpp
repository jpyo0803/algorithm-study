// N번째 큰 수
// https://www.acmicpc.net/problem/2075

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  priority_queue<int> pq;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int x;
      cin >> x;
      pq.push(-x);
    }

    while (pq.size() > n) pq.pop();
  }

  cout << -pq.top() << "\n";

  return 0;
}
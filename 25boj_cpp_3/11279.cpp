// 최대 힙 
// https://www.acmicpc.net/problem/11279

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  
  priority_queue<int> pq;
  while (n--) {
    int x;
    cin >> x;
    if (x == 0) {
      int v = 0;
      if (pq.size()) {
        v = pq.top();
        pq.pop();
      }
      cout << v << "\n";
    } else {
      pq.push(x);
    }
  }

  return 0;
}
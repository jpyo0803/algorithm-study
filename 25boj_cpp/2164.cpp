// 카드2
// https://www.acmicpc.net/problem/2164

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    q.push(i);
  }

  while (q.size() > 1) {
    q.pop();
    q.push(q.front());
    q.pop();
  }

  cout << q.front() << "\n";

  return 0;
}
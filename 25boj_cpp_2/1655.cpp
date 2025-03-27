// 가운데를 말해요
// https://www.acmicpc.net/problem/1655

/*
  두개의 우선순위큐를 활용한다.
  현재값 x는 왼쪽 우선순위큐에 포함된 모든 원소보다 크거나 같아야한다.
  현재값 x는 오른쪽 우선순위큐에 포함된 모든 원소보다 작거나 같아야한다.

  if lpq.top() >= x, then lpq.push(x)
  if -rpq.top() < x, then rpq.push(x)
  lpq.top() <= -rpq.top()

  and balance
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  priority_queue<int> lpq, rpq;
  lpq.push(-1e9);
  rpq.push(-1e9);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    if (lpq.top() < x) {
      rpq.push(-x);
    } else {
      lpq.push(x);
    }

    if (lpq.size() > rpq.size() + 1) {
      rpq.push(-lpq.top());
      lpq.pop();
    } else if (lpq.size() < rpq.size()) {
      lpq.push(-rpq.top());
      rpq.pop();
    }

    cout << lpq.top() << "\n";
  }

  return 0;
}
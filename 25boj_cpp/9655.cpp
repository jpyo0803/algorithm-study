// 돌 게임
// https://www.acmicpc.net/problem/9655

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  // 홀수 또는 짝수 상태는 처음 정해지면 바뀌지않는 invariant이다.
  // 만약 내턴에 짝수 상태이면 무조건 패배

  if (n % 2 == 0) {
    cout << "CY\n";
  } else {
    cout << "SK\n";
  }

  return 0;
}
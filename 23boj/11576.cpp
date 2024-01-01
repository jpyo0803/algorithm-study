// Base Conversion
// https://www.acmicpc.net/problem/11576

#include <bits/stdc++.h>

using namespace std;

int Powd(int b, int e) {
  if (e == 0) return 1;
  int x = Powd(b, e / 2);
  return x * x * (e % 2 ? b : 1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int A, B;
  cin >> A >> B;

  int m;
  cin >> m;

  int num = 0;
  while (m--) {
    int x;
    cin >> x;
    num += x * Powd(A, m);
  }

  stack<int> ans;
  while (true) {
    int r = num % B;
    num /= B;
    ans.push(r);
    if (num == 0) break;
  }

  while (ans.empty() == false) {
    cout << ans.top() << " ";
    ans.pop();
  }

  return 0;
}
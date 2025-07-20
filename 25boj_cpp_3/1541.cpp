// 잃어버린 괄호
// https://www.acmicpc.net/problem/1541

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  stack<int> num_stk;
  stack<char> op_stk;

  string s;
  cin >> s;

  int num = 0;
  for (auto ch : s) {
    if (ch == '+' || ch == '-') {
      op_stk.push(ch);
      num_stk.push(num);
      num = 0;
    } else {
      num = num * 10 + (ch - '0');
    }
  }

  num_stk.push(num);

  int ans = 0;
  int sum = 0;

  while (op_stk.size()) {
    if (op_stk.top() == '-') {
      ans -= sum + num_stk.top();
      sum = 0;
    } else { // +
      sum += num_stk.top();
    }
    op_stk.pop();
    num_stk.pop();
  }

  ans += sum + num_stk.top();

  cout << ans << "\n";

  return 0;
}
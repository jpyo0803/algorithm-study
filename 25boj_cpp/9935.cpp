// 문자열 폭발
// https://www.acmicpc.net/problem/9935

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string a, b;
  cin >> a >> b;

  reverse(b.begin(), b.end());

  stack<char> stk, stk2;
  for (auto ch : a) stk.push(ch);

  int mc = 0;
  while (stk.size()) {
    char x = stk.top();
    stk.pop();

    stk2.push(x);
    if (b[mc] == stk2.top()) {
      mc++;
      if (mc == b.length()) {
        int mcc = mc;
        while (mcc--) stk2.pop();
        mcc = mc - 1;
        while (stk2.size() && mcc--) {
          stk.push(stk2.top());
          stk2.pop();
        }
        mc = 0;
      }
    } else {
      while (mc > 0) {
        stk.push(stk2.top());
        stk2.pop();
        mc--;
      }
    }
  }


  if (stk2.empty()) cout << "FRULA\n";
  else {
    while (stk2.empty() == false) {
      cout << stk2.top();
      stk2.pop();
    }
    cout << "\n";
  }

  return 0;
}
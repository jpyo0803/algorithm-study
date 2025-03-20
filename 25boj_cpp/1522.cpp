// 문자열 교환
// https://www.acmicpc.net/problem/1522

#include <bits/stdc++.h>

using namespace std;

int Solve(const string& s, char ch, int width) {
  int ret = 0;

  int cnt = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == ch) cnt++;
    if (i >= width) {
      if (s[i - width] == ch) cnt--;
      ret = max(ret, cnt);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int a_cnt, b_cnt;
  a_cnt = b_cnt = 0;

  for (auto ch : s) {
    if (ch == 'a') a_cnt++;
    else b_cnt++;
  }

  if (a_cnt > 0 && b_cnt > 0) {
    queue<char> que;
    for (auto ch : s) que.push(ch);

    while (que.back() == que.front()) {
      que.push(que.front());
      que.pop();
    }

    s.clear();
    while (que.empty() == false) {
      s.push_back(que.front());
      que.pop();
    }
  }

  int ans_a = Solve(s, 'a', a_cnt);
  int ans_b = Solve(s, 'b', b_cnt);

  cout << min(a_cnt - ans_a, b_cnt - ans_b) << "\n";

  return 0;
}
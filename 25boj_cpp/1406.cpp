// 에디터
// https://www.acmicpc.net/problem/1406

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  list<char> lst;

  string in;
  cin >> in;

  for (auto ch : in) {
    lst.push_back(ch);
  }

  int m;
  cin >> m;

  auto it = lst.end();

  while (m--) {
    char op;
    cin >> op;
    if (op == 'L') {
      if (it != lst.begin()) it--;
    } else if (op == 'D') {
      if (it != lst.end()) it++;
    } else if (op == 'B') {
      if (it != lst.begin()) {
        auto tit = it;
        it--;
        lst.erase(it);
        it = tit;
      }
    } else {
      char ch;
      cin >> ch;
      lst.insert(it, ch);
    }
  }

  for (auto ch : lst) {
    cout << ch << "";
  }
  cout << "\n";

  return 0;
}
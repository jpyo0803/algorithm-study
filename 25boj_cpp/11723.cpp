// 집합
// https://www.acmicpc.net/problem/11723

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int m;
  cin >> m;

  set<int> ss;

  string op;
  int arg;

  while (m--) {
    cin >> op;
    if (op != "all" && op != "empty") {
      cin >> arg;
    }

    if (op == "add") {
      ss.insert(arg);
    } else if (op == "remove") {
      ss.erase(arg);
    } else if (op == "check") {
      auto it = ss.find(arg);
      if (it == ss.end()) {
        cout << "0\n";
      } else {
        cout << "1\n";
      }
    } else if (op == "toggle") {
      auto it = ss.find(arg);
      if (it == ss.end()) {
        ss.insert(arg);
      } else {
        ss.erase(arg);
      }
    } else if (op == "all") {
      for (int i = 1; i <= 20; ++i) {
        ss.insert(i);
      }
    } else if (op == "empty") {
      ss.clear();
    } else {
      assert(false); // something wrong
    }
  }

  return 0;
}
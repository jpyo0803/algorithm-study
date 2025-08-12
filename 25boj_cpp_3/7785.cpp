// 회사에 있는 사람
// https://www.acmicpc.net/problem/7785

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  set<string, std::greater<string>> ss;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    if (b[0] == 'e') {
      ss.insert(a);
    } else {
      auto it = ss.find(a);
      if (ss.end() != it) {
        ss.erase(it);
      }
    }
  }
  
  for (auto& e : ss) {
    cout << e << "\n";
  }

  return 0;
}
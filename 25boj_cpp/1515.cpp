// 수 이어 쓰기 
// https://www.acmicpc.net/problem/1515

#include <bits/stdc++.h>

using namespace std;

string ss;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> ss;
  int i = 1;
  int j = 0;

  int ans = 0;
  while (j < ss.length()) {
    string istr = to_string(i);
    for (auto ch : istr) {
      if (ch == ss[j]) {
        j++;
        ans = i;
      }
    }
    i++;
  }

  cout << ans << "\n";

  return 0;
}
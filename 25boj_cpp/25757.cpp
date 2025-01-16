// 임스와 함께하는 미니게임
// https://www.acmicpc.net/problem/25757

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  char ch;
  cin >> n >> ch;

  int num_ppl;
  if (ch == 'Y') num_ppl = 2;
  else if (ch == 'F') num_ppl = 3;
  else num_ppl = 4;

  set<string> ppl;
  while (n--) {
    string s;
    cin >> s;
    ppl.insert(s);
  }

  cout << ppl.size() / (num_ppl - 1) << "\n";

  return 0;
}
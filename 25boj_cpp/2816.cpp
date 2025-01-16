// 디지털 티비
// https://www.acmicpc.net/problem/2816

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  int pos_kbs1, pos_kbs2;
  pos_kbs1 = pos_kbs2 = -1;

  vector<string> lst;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    lst.push_back(s);
    if (lst.back() == "KBS1") {
      assert(pos_kbs1 == -1);
      pos_kbs1 = i;
    } else if (lst.back() == "KBS2") {
      assert(pos_kbs2 == -1);
      pos_kbs2 = i;
    }
  }

  string ans;

  for (int i = 0; i < pos_kbs1; ++i) ans.push_back('1');
  for (int i = 0; i < pos_kbs1; ++i) ans.push_back('4');
  
  if (pos_kbs2 < pos_kbs1) {
    pos_kbs2++;
  }

  for (int i = 0; i < pos_kbs2; ++i) ans.push_back('1');
  for (int i = 0; i < pos_kbs2 - 1; ++i) ans.push_back('4');
  
  for (auto ch : ans) {
    cout << ch;
  }
  cout << "\n";

  return 0;
}
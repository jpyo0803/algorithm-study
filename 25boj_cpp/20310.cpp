// 타노스
// https://www.acmicpc.net/problem/20310

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;

  int zc = 0;
  int oc = 0;
  for (auto ch : s) {
    if (ch == '0')
      zc++;
    else
      oc++;
  }

  zc /= 2;
  oc /= 2;

  int s_len = s.length();

  vector<bool> masking(s_len, true);

  int j = s_len - 1;
  while (zc) {
    if (s[j] == '0') {
      masking[j] = false;
      zc--;
    }
    j--;
  }

  j = 0;
  while (oc) {
    if (s[j] == '1') {
      masking[j] = false;
      oc--;
    }
    j++;
  }

  string ans;
  for (int i = 0; i < s_len; ++i) {
    if (masking[i] == true) {
      ans.push_back(s[i]);
    }
  }

  cout << ans << "\n";

  return 0;
}
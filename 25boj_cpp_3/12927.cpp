// 배수 스위치 
// https://www.acmicpc.net/problem/12927

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  
  int ans = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == 'Y') {
      ans++;
      for (int j = i; j < s.length(); j += (i + 1)) {
        s[j] = s[j] == 'Y' ? 'N' : 'Y';
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
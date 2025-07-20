// 필사의 문자열
// https://www.acmicpc.net/problem/34051

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  string s;
  cin >> s;

  multiset<char> cms;
  for (int i = 1; i < n; ++i) cms.insert(s[i]);
  
  for (int i = 0; i < n - 1; ++i) {
    auto it = cms.upper_bound(s[i]);
    if (it != cms.end()) {
      string cand;
      cand.push_back(s[i]);
      for (int j = i + 1; j < n; ++j) {
        string ss = s.substr(i, j - i + 1);
        reverse(ss.begin(), ss.end());
        if (cand < ss.substr(0, cand.size())) {
          swap(cand, ss);
        }
      }

      for (int j = 0; j < cand.size(); ++j) s[i + j] = cand[j];

      break;
    } 

    auto fit = cms.find(s[i]);
    if (fit != cms.end()) cms.erase(fit);
  }

  cout << s << "\n";

  return 0;
}
// Creating Strings 
// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>

using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  cin >> s;
  
  sort(s.begin(), s.end());

  vector<string> ans;
  do {
    ans.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << ans.size() << "\n";
  for (auto& e : ans) cout << e << "\n";

  return 0;
}
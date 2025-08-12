// 듣보잡
// https://www.acmicpc.net/problem/1764

#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;
  
  set<string> ss;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    ss.insert(s);
  }

  vector<string> ans;
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    if (ss.find(s) != ss.end()) ans.push_back(s);
  }

  vector<int> ind(ans.size());
  for (int i = 0; i < ans.size(); ++i) ind[i] = i;
  sort(ind.begin(), ind.end(), [&](int a, int b) {
    return ans[a] < ans[b];
  });

  cout << ans.size() << "\n";
  for (auto i : ind) {
    cout << ans[i] << "\n";
  }

  return 0;
}
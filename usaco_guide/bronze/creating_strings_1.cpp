// Creating Strings 1
// https://cses.fi/problemset/task/1622

#include <bits/stdc++.h>

using namespace std;

int cnt[26];

string input;
vector<int> idxs;

vector<string> ans;

void Search(string& cand) {
  if (cand.size() == input.size()) {
    ans.push_back(cand);
    return;
  }

  for (auto idx : idxs) {
    if (cnt[idx] == 0) continue;
    cnt[idx]--;
    cand.push_back('a' + idx);
    Search(cand);
    cand.pop_back();
    cnt[idx]++;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> input;
  for (auto ch : input) {
    ++cnt[ch - 'a'];
  }

  for (int i = 0; i < 26; ++i) {
    if (cnt[i] > 0) {
      idxs.push_back(i);
    }
  }

  string cand;
  Search(cand);

  cout << ans.size() << "\n";
  for (auto& e : ans) {
    cout << e << "\n";
  }

  return 0;
}
// 영단어 암기는 괴로워
// https://www.acmicpc.net/problem/20920

#include <bits/stdc++.h>

using namespace std;

bool compare(const pair<string, int>& x, const pair<string, int>& y) {
  if (x.second == y.second) {
    int x_len = x.first.length();
    int y_len = y.first.length();
    if (x_len == y_len) {
      for (int i = 0; i < x_len; ++i) {
        if (x.first[i] == y.first[i]) continue;
        return x.first[i] < y.first[i];
      }
    } else {
      return x_len > y_len;
    }
  } else {
    return x.second > y.second;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> words;
  map<string, int> freq;

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    if (s.length() < m) continue;
    words.push_back(s);
    freq[s]++;
  }

  vector<pair<string, int>> wfv;
  for (const auto& [k, v] : freq) {
    wfv.emplace_back(k, v);
  }

  sort(wfv.begin(), wfv.end(), compare);

  for (const auto& [k, v] : wfv) {
    cout << k << "\n";
  }

  return 0;
}
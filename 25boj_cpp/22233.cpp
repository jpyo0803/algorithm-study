// 가희와 키워드
// https://www.acmicpc.net/problem/22233

#include <bits/stdc++.h>

using namespace std;

int n, m;

void Tokenizer(vector<string>& res, const string& in) {
  string token;

  for (auto ch : in) {
    if (ch == ',') {
      res.push_back(token);
      token.clear();
    } else {
      token.push_back(ch);
    }
  }

  if (token.empty() == false) {
    res.push_back(token);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> m;

  set<string> keywords;
  for (int i = 0; i < n; ++i) {
    string x;
    cin >> x;
    keywords.insert(x);
  }

  for (int i = 0; i < m; ++i) {
    string x;
    cin >> x;


    vector<string> tokens;
    Tokenizer(tokens, x);

    for (auto& token : tokens) {
      auto it = keywords.find(token);
      if (it != keywords.end()) {
        keywords.erase(it);
      }
    }
    cout << keywords.size() << "\n";
  }

  return 0;
}
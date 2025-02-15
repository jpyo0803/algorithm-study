// 단축키 지정
// https://www.acmicpc.net/problem/1283

#include <bits/stdc++.h>

using namespace std;

int n;

bool used_char[256];

bool RegisterChar(char ch) {
  if (ch >= 'a' && ch <= 'z') {
    ch += 'A' - 'a';
  }
  if (used_char[ch] == true) return false;  // fail to register

  used_char[ch] = true;
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  cin.ignore();

  vector<vector<string>> vv(n);

  for (int i = 0; i < n; ++i) {
    string s;
    getline(cin, s);

    string token;
    for (auto ch : s) {
      if (ch == ' ') {
        vv[i].push_back(token);
        token.clear();
      } else {
        token.push_back(ch);
      }
    }
    if (token.empty() == false) {
      vv[i].push_back(token);
    }
  }

  for (int i = 0; i < n; ++i) {
    bool ok = false;
    for (auto& token : vv[i]) {
      char f = token[0];
      if (RegisterChar(f)) {
        string new_token = "["; new_token.push_back(f); new_token.push_back(']');
        new_token += token.substr(1, token.length() - 1);
        swap(token, new_token);
        ok = true;
        break;
      }
    }

    if (ok) {
      for (const auto& token : vv[i]) {
        cout << token << " ";
      }
      cout << "\n";
      continue;
    }

    for (auto& token : vv[i]) {
      int token_len = token.length();
      for (int i = 0; i < token_len; ++i) {
        char ch = token[i];
        if (RegisterChar(ch)) {
          string new_token = token.substr(0, i);
          new_token.push_back('['); new_token.push_back(ch); new_token.push_back(']');
          new_token += token.substr(i + 1, token_len - i - 1);
          swap(token, new_token);
          ok = true;
          break;
        }
      }
      if (ok) break;
    }

    for (const auto& token : vv[i]) {
      cout << token << " ";
    }
    cout << "\n";
  }

  return 0;
}
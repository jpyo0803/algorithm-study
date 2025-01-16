// 비밀번호 발음하
// https://www.acmicpc.net/problem/4659

#include <bits/stdc++.h>

using namespace std;

bool is_vowel(char ch) {
  if (ch == 'a') return true;
  else if (ch == 'e') return true;
  else if (ch == 'i') return true;
  else if (ch == 'o') return true;
  else if (ch == 'u') return true;
  return false;
}

bool has_vowel(const string& s) {
  for (auto ch : s) {
    if (is_vowel(ch)) return true;
  }
  return false;
}

bool has_no_3seq(const string& s) {
  int len = s.length();
  for (int i = 0; i < len - 2; ++i) {
    bool vowel_check = true;
    bool conso_check = false;

    for (int j = 0; j < 3; ++j) {
      bool res = is_vowel(s[i + j]);
      vowel_check &= res; // 하나라도 vowel이 아니면 false가됨
      conso_check |= res; // 하나라도 consonant가 아니면 true가됨
    }
    if (vowel_check == true || conso_check == false) return false;
  }
  return true;
}

bool has_no_2same(const string& s) {
  int len = s.length();
  for (int i = 0; i < len - 1; ++i) {
    char ch1 = s[i];
    char ch2 = s[i + 1];
    if (ch1 != 'e' && ch2 != 'o') {
      if (ch1 == ch2) return false; 
    }
  }
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  string s;
  while (true) {
    cin >> s;
    if (s == "end") break;

    bool ans = true;
    ans &= has_vowel(s);
    ans &= has_no_3seq(s);
    ans &= has_no_2same(s);

    cout << "<" << s << "> is ";
    if (!ans) {
      cout << "not ";
    }
    cout << "acceptable.\n";
  }

  return 0;
}
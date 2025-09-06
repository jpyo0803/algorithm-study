// 가르침 
// https://www.acmicpc.net/problem/1062

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n, k;
bool chosen[256];
vector<string> words;
vector<char> cands;

int Solve(int d, int prev) {
  if (d >= k) {
    int cnt = 0;
    for (auto& w : words) {
      bool ok = true;
      for (auto ch : w) {
        if (chosen[ch] == false) {
          ok = false;
          break;
        }
      }
      if (ok) cnt++;
    }
    return cnt;
  }

  int ret = 0;
  for (int i = prev + 1; i < cands.size(); ++i) {
    chosen[cands[i]] = true;
    ret = max(ret, Solve(d + 1, i));
    chosen[cands[i]] = false;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  cin >> n >> k;
  k -= 5;
  chosen['a'] = chosen['n'] = chosen['t'] = chosen['i'] = chosen['c'] = true;

  for (char ch = 'a'; ch <= 'z'; ++ch) {
    if (ch == 'a' || ch == 'n' || ch == 't' || ch == 'i' || ch == 'c') continue;
    cands.push_back(ch);
  }

  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    words.push_back(s.substr(4, s.length() - 8));
  }

  if (k < 0) {
    cout << "0\n";
  } else {
    cout << Solve(0, -1) << "\n";
  }

  return 0;
}
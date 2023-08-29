// FEB
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1323

#include <bits/stdc++.h>

using namespace std;

pair<int, int> DoWork(const string& S, int s, int e) {
  int len = e - s;
  int N = S.length();

  // diff -> |F|-1+1
  // same -> |F|-1+2
  // both no exist -> |F|-1
  // one side -> |F|+1

  char l = S[s - 1], r = S[e];

  pair<int, int> ret;

  if (l == r) {          // same
    if (len % 2 == 0) {  // even length
      ret.first = 1;
      ret.second = len - 1 + 2;
    } else {  // odd length
      ret.first = 0;
      ret.second = len - 1 + 2;
    }
  } else {
    if (len % 2 == 0) {  // even length
      ret.first = 0;
      ret.second = len - 1 + 1;
    } else {  // odd length
      ret.first = 1;
      ret.second = len - 1 + 1;
    }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  string S;
  cin >> S;

  int len = S.length();

  int offset = 0;
  for (int i = 0; i < len - 1; ++i) {
    if (S[i] == 'E' && S[i + 1] == 'E')
      offset++;
    else if (S[i] == 'B' && S[i + 1] == 'B')
      offset++;
  }

  int s = -1, e = -1;
  int i = 0;

  int l = 0, r = 0;

  int ff = 0;
  while (true) {
    if (i < len && S[i] == 'F') {
      if (s == -1) {
        s = i;
      }
    } else {
      // not F
      if (s != -1) {
        e = i;

        int x = e - s;
        if (s == 0 && e == len) {
          ff += x - 1;
        } else if (s == 0 || e == len) {
          ff += x;
        } else {
          auto res = DoWork(S, s, e);
          l += res.first;
          r += res.second;
        }

        s = e = -1;
      }
      if (i == len) break;
    }
    i++;
  }

  vector<int> ss;
  for (int i = r + offset; i >= l + offset; i -= 2) {
    ss.push_back(i);
  }

  set<int> ans;
  for (int i = 0; i <= ff; ++i) {
    for (auto e : ss) {
      ans.insert(e + i);
    }
  }

  cout << ans.size() << "\n";
  for (auto e : ans) {
    cout << e << "\n";
  }

  return 0;
}
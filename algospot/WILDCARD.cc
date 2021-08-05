//
// WILDCARD
// Problem: https://algospot.com/judge/problem/read/WILDCARD
//

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int C, N;
string W, S;

int cache[101][101];

bool match(int w, int s) {
  int& ret = cache[w][s];

  if (ret != -1) return ret;

  while (w < W.size() && s < S.size() && (W[w] == S[s] || W[w] == '?')) {
    w++;
    s++;
  }

  if (w == W.size()) return ret = (s == S.size());

  if (W[w] == '*') {
    for (int i = 0; i + s <= S.size(); i++) {
      if (match(w + 1, s + i)) {
        return ret = 1;
      }
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<string> ans;
  cin >> C;
  for (int c = 0; c < C; c++) {
    cin >> W >> N;
    for (int n = 0; n < N; n++) {
      memset(cache, -1, sizeof(cache));
      cin >> S;
      if (match(0, 0)) {
        ans.push_back(S);
      }
    }
    sort(ans.begin(), ans.end());

    for (auto& e : ans) {
      cout << e << endl;
    }

    ans.clear();
  }

  return 0;
}
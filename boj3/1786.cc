//
// Search
// Problem: https://www.acmicpc.net/problem/1786
//

#include <iostream>
#include <vector>

using namespace std;

constexpr int kMaxLength = 1000000;
int pi[kMaxLength + 1];

void GetPartialMatch(string& key) {
  int begin = 1, matched = 0;

  int m = key.length();

  while (begin + matched < m) {
    if (key[begin + matched] == key[matched]) {
      matched += 1;
      pi[begin + matched - 1] = matched;
    } else {
      if (matched == 0) {
        begin += 1;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
}

void KMPSearch(vector<int>& ans, string& hay, string& key) {
  GetPartialMatch(key);

  int n = hay.length();
  int m = key.length();

  int begin = 0, matched = 0;

  while (begin <= n - m) {
    if (matched < m && hay[begin + matched] == key[matched]) {
      matched += 1;
      if (matched == m) {
        ans.push_back(begin + 1);
      }
    } else {
      if (matched == 0) {
        begin += 1;
      } else {
        begin += matched - pi[matched - 1];
        matched = pi[matched - 1];
      }
    }
  }
}

vector<int> ans;
string hay, key;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getline(cin, hay);
  getline(cin, key);

  KMPSearch(ans, hay, key);

  cout << ans.size() << "\n";
  for (auto& e : ans) {
    cout << e << "\n";
  }
  return 0;
}

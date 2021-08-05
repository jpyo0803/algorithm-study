//
// Phone Number Book
// Problem: https://www.acmicpc.net/problem/5052
// TODO : Try index-based Trie
//

#include <iostream>
#include <string>

using namespace std;

int t, n;
char input[11];

constexpr int kNumber = 10;

int ToNumber(char ch) { return ch - '0'; }

class TrieNode {
 public:
  TrieNode() : terminal_{false} {
    for (int i = 0; i < kNumber; i++) children_[i] = nullptr;
  }

  bool CheckAndInsert(const char* digit) {
    if (terminal_) return false;

    if (*digit == '\0') {
      for (int i = 0; i < kNumber; i++) {
        if (children_[i] != nullptr) {
          return false;
        }
      }
      terminal_ = true;
      return true;
    }

    int next = ToNumber(*digit);
    if (children_[next] == nullptr) {
      children_[next] = new TrieNode();
    }
    return children_[next]->CheckAndInsert(digit + 1);
  }

  bool terminal_;
  TrieNode* children_[kNumber];
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    cin >> n;
    TrieNode* base = new TrieNode();

    bool possible = true;
    for (int i = 0; i < n; i++) {
      cin >> input;
      if (!base->CheckAndInsert(input)) {
        possible = false;
      }
    }
    if (possible) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}


//
// String Set
// Problem: https://www.acmicpc.net/problem/14425
// TODO : Do it with efficient way
//

#include <cstdio>

constexpr int ALPHABET = 26;
int N, M;
char input[501];

int ToNumber(char ch) { return ch - 'a'; }

class TrieNode {
 public:
  TrieNode() : terminal_{false} {
    for (int i = 0; i < ALPHABET; i++) children_[i] = nullptr;
  }

  void Insert(const char* ch) {
    if (*ch == '\0') {
      terminal_ = true;
    } else {
      int next = ToNumber(*ch);
      if (children_[next] == nullptr) {
        children_[next] = new TrieNode();
      }
      children_[next]->Insert(ch + 1);
    }
  }

  TrieNode* Find(const char* ch) {
    if (*ch == '\0' && terminal_) return this;

    int next = ToNumber(*ch);
    if (children_[next] == nullptr) {
      return nullptr;
    }
    return children_[next]->Find(ch + 1);
  }

  bool terminal_;
  TrieNode* children_[ALPHABET];
};

int main() {
  TrieNode* base = new TrieNode();
  scanf("%d%d", &N, &M);
  for (int i = 0; i < N; i++) {
    scanf("%s", input);
    base->Insert(input);
  }

  int ans = 0;
  for (int i = 0; i < M; i++) {
    scanf("%s", input);
    TrieNode* ret = base->Find(input);
    if (ret != nullptr) {
      ans += 1;
    }
  }
  printf("%d", ans);
  return 0;
}
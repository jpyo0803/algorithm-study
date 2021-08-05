// 휴대폰 자판
// https://www.acmicpc.net/problem/5670

#include <stdio.h>
#include <string.h>

#include <string>
#include <vector>

using namespace std;

constexpr size_t kNumChildren = 26;

char input[82];
int N;
vector<string> words;

int CharToOrd(char ch) { return ch - 'a'; }

struct TrieNode {
  bool is_complete;
  bool is_root;
  int num_child;

  TrieNode* children[kNumChildren];

  TrieNode() : is_complete(false), is_root(false), num_child(0) {
    for (size_t i = 0; i < kNumChildren; i++) children[i] = nullptr;
  }

  explicit TrieNode(bool _is_root)
      : is_complete(false), is_root(_is_root), num_child(0) {
    for (size_t i = 0; i < kNumChildren; i++) children[i] = nullptr;
  }

  ~TrieNode() {
    for (size_t i = 0; i < kNumChildren; i++) {
      if (children[i] != nullptr) delete children[i];
    }
  }

  void Insert(const char* p) {
    if (*p == 0) {
      is_complete = true;
      return;
    }

    int ord = CharToOrd(*p);
    if (children[ord] == nullptr) {
      children[ord] = new TrieNode();
      num_child++;
    }
    children[ord]->Insert(p + 1);
  }

  int Find(const char* p) {
    if (*p == 0) return 0;

    int ord = CharToOrd(*p);
    int ret = children[ord]->Find(p + 1);

    if (is_root || num_child > 1 || is_complete) ret += 1;
    return ret;
  }
};

int main() {
  while (scanf("%d", &N) != EOF) {
    words.reserve(N);
    TrieNode* tn_root = new TrieNode(true);
    for (int n = 0; n < N; n++) {
      scanf("%s", input);
      input[strlen(input)] = 0;
      int ord = CharToOrd(input[0]);
      tn_root->Insert(input);
      words.push_back(input);
    }

    int total_sum = 0;
    for (auto& word : words) {
      int ord = CharToOrd(word.c_str()[0]);
      int ret = tn_root->Find(word.c_str());
      total_sum += ret;
    }
    printf("%.2lf\n", static_cast<double>(total_sum) / N);
    words.clear();
    delete tn_root;
  }

  return 0;
}

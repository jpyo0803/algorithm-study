// 개미굴
// https://www.acmicpc.net/problem/14725

#include <stdio.h>

#include <set>
#include <string>
#include <vector>

using namespace std;

constexpr size_t kNumAlphabet = 26;

int N, K;
char input[16];
vector<string> words;

size_t ToNumber(char ch) { return ch - 'A'; }

struct TrieNode {
  set<string> contents;

  TrieNode* children[kNumAlphabet];

  TrieNode() {
    for (size_t i = 0; i < kNumAlphabet; i++) children[i] = nullptr;
  }

  ~TrieNode() {
    for (size_t i = 0; i < kNumAlphabet; i++) {
      if (children[i]) delete children[i];
    }
  }

  void Insert(const vector<string>& words, int nth) {
    if (nth == words.size()) return;

    int index = ToNumber(words[nth][0]);
    if (!children[index]) {
      children[index] = new TrieNode();
    }

    contents.insert(words[nth]);
    children[index]->Insert(words, nth + 1);
  }
  void Traverse(int nth) {
    for (auto& content : contents) {
      for (int i = 0; i < nth; i++) printf("--");
      printf("%s\n", content.c_str());

      int index = ToNumber(content[0]);
      children[index]->Traverse(nth + 1);
    }
  }
};

int main() {
  TrieNode* root = new TrieNode();
  words.reserve(15);

  scanf("%d", &N);
  for (int n = 0; n < N; n++) {
    scanf("%d", &K);
    words.clear();
    for (int k = 0; k < K; k++) {
      scanf("%s", input);
      words.push_back(input);
    }
    root->Insert(words, 0);
  }

  root->Traverse(0);

  delete root;
  return 0;
}

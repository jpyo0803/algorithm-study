// 전화번호 목록
// https://programmers.co.kr/learn/courses/30/lessons/42577

#include <string>
#include <vector>

using namespace std;

int CharToInt(char ch) { return ch - '0'; }

struct Trie {
  bool complete;

  Trie* t[10];

  Trie() : complete(false) {
    for (int i = 0; i < 10; ++i) {
      t[i] = nullptr;
    }
  }

  ~Trie() {
    for (int i = 0; i < 10; ++i) {
      if (t[i] != nullptr) {
        delete t[i];
      }
    }
  }

  bool Insert(const char* ch) {
    if (complete) return false;  // prefix already exist
    if (*ch == '\0') {
      complete = true;
      return true;
    }

    int index = CharToInt(*ch);
    if (t[index] == nullptr) {
      t[index] = new Trie();
    } else {
      if (*(ch + 1) == '\0') {
        return false;
      }
    }

    return t[index]->Insert(ch + 1);
  }
};

bool solution(vector<string> phone_book) {
  bool answer = true;
  Trie* trie = new Trie();
  for (auto& pn : phone_book) {
    bool ret = trie->Insert(pn.c_str());
    if (!ret) {
      answer = false;
      break;
    }
  }

  return answer;
}
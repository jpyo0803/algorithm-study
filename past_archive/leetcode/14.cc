// 14. Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/

// Version 1: Trie

namespace {
int max_len;
string ans;
int ne;
}  // namespace

class Solution {
 public:
  struct Trie {
    static int CharToInt(char ch) { return ch - 'a'; }

    Trie* children[26];

    int check_count[26];

    Trie() {
      for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
        check_count[i] = 0;
      }
    }

    ~Trie() {
      for (int i = 0; i < 26; ++i) {
        if (children[i] == nullptr) continue;
        delete children[i];
      }
    }

    void Insert(string& cand, const char* p) {
      if (*p == '\0') return;

      cand.push_back(*p);

      int ind = CharToInt(*p);

      if (children[ind] == nullptr) {
        children[ind] = new Trie();
      }

      ++check_count[ind];
      if (check_count[ind] == ne && max_len < cand.size()) {
        max_len = cand.size();
        ans = cand;
      }

      children[ind]->Insert(cand, p + 1);
    }
  };

  string longestCommonPrefix(vector<string>& strs) {
    max_len = 0;
    ans.clear();
    ne = strs.size();

    Trie* root = new Trie();

    for (int i = 0; i < strs.size(); ++i) {
      string cand;
      root->Insert(cand, strs[i].c_str());
    }
    return ans;
  }
};

// Version 2: Simple Brute Force
class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    string ans;

    int i = 0;
    while (true) {
      int j = 0;
      bool pass = true;
      bool first = true;

      char ch;
      for (auto& str : strs) {
        if (str.size() <= i) {
          pass = false;
          break;
        }
        if (first) {
          ch = str[i];
          first = false;
        } else {
          if (str[i] != ch) {
            pass = false;
            break;
          }
        }
      }
      if (!pass) break;
      ans.push_back(ch);
      ++i;
    }

    return ans;
  }
};
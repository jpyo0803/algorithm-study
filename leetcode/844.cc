// 844. Backspace String Compare
// https://leetcode.com/problems/backspace-string-compare/

// Stack way
class Solution {
 public:
  bool backspaceCompare(string s, string t) {
    stack<char> ss, st;
    for (auto ch : s) {
      if (ch == '#') {
        if (!ss.empty()) ss.pop();
      } else {
        ss.push(ch);
      }
    }

    for (auto ch : t) {
      if (ch == '#') {
        if (!st.empty()) st.pop();
      } else {
        st.push(ch);
      }
    }

    if (ss.size() != st.size()) return false;
    while (!ss.empty()) {
      if (ss.top() != st.top()) return false;
      ss.pop();
      st.pop();
    }

    return true;
  }
};

// Try with Two Pointer?
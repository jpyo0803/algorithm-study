// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;

    for (auto ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        stk.push(ch);
      } else {
        char other;
        if (ch == ')')
          other = '(';
        else if (ch == ']')
          other = '[';
        else if (ch == '}')
          other = '{';
        if (stk.empty() || other != stk.top()) {
          stk.push(ch);
          break;
        }
        stk.pop();
      }
    }

    return stk.empty();
  }
};

// Second Try
class Solution {
 public:
  bool isValid(string s) {
    stack<char> stk;

    for (auto ch : s) {
      if (ch == '(' || ch == '[' || ch == '{') {
        stk.push(ch);
      } else {
        if (stk.empty()) return false;

        if (ch == ')' && stk.top() != '(')
          return false;
        else if (ch == ']' && stk.top() != '[')
          return false;
        else if (ch == '}' && stk.top() != '{')
          return false;
        stk.pop();
      }
    }
    return stk.empty();
  }
};
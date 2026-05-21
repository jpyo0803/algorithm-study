// 8. String To Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

class Solution {
 public:
  static bool IsWhiteSpace(char ch) { return ch == ' '; }

  static bool IsSign(char ch) { return ch == '-' || ch == '+'; }

  static bool IsPeriod(char ch) { return ch == '.'; }

  static bool IsDigit(char ch) { return ch >= '0' && ch <= '9'; }

  static long long int CharToInt(char ch) { return ch - '0'; }

  static int StrToInt(const string& s, char sign) {
    long long int num = 0;

    long long int sign_int = sign == '+' ? 1 : -1;
    for (auto ch : s) {
      num = num * 10 + CharToInt(ch) * sign_int;
      if (num > INT_MAX) {
        num = INT_MAX;
        break;
      }
      if (num < INT_MIN) {
        num = INT_MIN;
        break;
      }
    }
    return static_cast<int>(num);
  }

  int myAtoi(string s) {
    int i = 0;
    while (IsWhiteSpace(s[i])) {
      ++i;
    }

    bool was_digit = false;
    bool was_sign = false;
    char sign = '+';

    string ss;
    for (; i < s.size(); ++i) {
      char ch = s[i];
      if (IsDigit(ch)) {
        if (!was_digit) was_digit = true;
        ss.push_back(ch);
      } else {
        if (IsPeriod(ch)) break;
        if (IsSign(ch)) {
          if (was_digit) break;
          if (!was_sign) {
            sign = ch;
            was_sign = true;
          } else {
            break;
          }
        } else {
          break;
        }
      }
    }

    if (ss.empty()) return 0;

    return StrToInt(ss, sign);
  }
};
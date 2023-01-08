// 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/

int pow_dp[5];

class Solution {
 public:
  static int Pow(int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return 10;
    if (pow_dp[exp] != -1) return pow_dp[exp];

    int ret = Pow(exp / 2);
    ret *= ret;
    if (exp % 2) ret *= 10;
    pow_dp[exp] = ret;
    return ret;
  }

  string intToRoman(int num) {  // num = 1 ~ 3999
    for (int i = 0; i < 5; ++i) pow_dp[i] = -1;
    int tmp = num;
    int num_digit = 0;

    while (tmp > 0) {
      tmp /= 10;
      ++num_digit;
    }

    num_digit;

    string ans;
    ans.reserve(50);
    while (num_digit > 0) {
      int m = Pow(num_digit - 1);
      int digit = num / m;
      int digit_m = digit * m;
      num %= m;
      if (digit_m >= 1000) {
        for (int i = 0; i < digit; ++i) {
          ans.append("M");
        }
      } else if (digit_m >= 100) {
        if (digit_m == 900) {
          ans.append("CM");
        } else if (digit_m >= 500) {
          ans.append("D");
          for (int i = 0; i < digit - 5; ++i) {
            ans.append("C");
          }
        } else if (digit_m == 400) {
          ans.append("CD");
        } else if (digit_m >= 100) {
          for (int i = 0; i < digit; ++i) {
            ans.append("C");
          }
        }
      } else if (digit_m >= 10) {
        if (digit_m == 90) {
          ans.append("XC");
        } else if (digit_m >= 50) {
          ans.append("L");
          for (int i = 0; i < digit - 5; ++i) {
            ans.append("X");
          }
        } else if (digit_m == 40) {
          ans.append("XL");
        } else if (digit_m >= 10) {
          for (int i = 0; i < digit; ++i) {
            ans.append("X");
          }
        }
      } else {
        if (digit_m == 9) {
          ans.append("IX");
        } else if (digit_m >= 5) {
          ans.append("V");
          for (int i = 0; i < digit - 5; ++i) {
            ans.append("I");
          }
        } else if (digit_m == 4) {
          ans.append("IV");
        } else if (digit_m >= 1) {
          for (int i = 0; i < digit; ++i) {
            ans.append("I");
          }
        }
      }
      --num_digit;
    }

    return ans;
  }
};
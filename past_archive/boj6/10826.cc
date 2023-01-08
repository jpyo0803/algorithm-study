// 피보나치 수 4
// https://www.acmicpc.net/problem/10826

#include <stdio.h>

#include <algorithm>
#include <string>

using namespace std;

int Abs(int x) { return x < 0 ? -x : x; }

struct BigInteger {
  string x;
  BigInteger(string _x) : x(_x) {}
  BigInteger operator+(BigInteger& other) {
    int diff = Abs(x.size() - other.x.size());

    if (x.size() > other.x.size()) {
      while (diff-- > 0) other.x.push_back('0');
    } else if (other.x.size() > x.size()) {
      while (diff-- > 0) x.push_back('0');
    }

    BigInteger ret("");
    ret.x.resize(x.size());
    bool carry = false;
    for (int i = 0; i < x.size(); i++) {
      int a = x[i] - '0';
      int b = other.x[i] - '0';
      int digit = a + b + carry;

      carry = false;
      if (digit >= 10) carry = true;
      digit %= 10;

      char ch_digit = digit + '0';
      ret.x[i] = ch_digit;
    }

    if (carry) {
      ret.x.push_back('1');
    }

    return ret;
  }

  string GetResult() {
    reverse(x.begin(), x.end());
    return x;
  }
};

int n;

string Solve(int n) {
  if (n == 0) return "0";
  if (n == 1) return "1";

  BigInteger pp("0");
  BigInteger p("1");
  for (int i = 2; i <= n; i++) {
    BigInteger tmp = p;
    p = p + pp;
    pp = tmp;
  }
  return p.GetResult();
}

int main() {
  scanf("%d", &n);
  printf("%s\n", Solve(n).c_str());
  return 0;
}

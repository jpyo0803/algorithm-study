// 조합
// https://www.acmicpc.net/problem/2407

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class BigInteger {
 public:
  BigInteger() = default;
  explicit BigInteger(string num) : num_(num) {
    reverse(num_.begin(), num_.end());
  }

  BigInteger operator+(const BigInteger& other) {
    BigInteger tmp;
    size_t larger =
        num_.size() < other.num_.size() ? other.num_.size() : num_.size();
    tmp.num_.reserve(larger + 1);

    bool carry = false;
    for (size_t i = 0; i < larger; i++) {
      int a = 0, b = 0;
      if (i < num_.size()) a = num_[i] - '0';
      if (i < other.num_.size()) b = other.num_[i] - '0';
      int c = a + b + (carry ? 1 : 0);

      carry = false;
      if (c >= 10) {
        carry = true;
        c %= 10;
      }
      tmp.num_.push_back(c + '0');
    }
    if (carry) tmp.num_.push_back('1');
    return tmp;
  }

  friend ostream& operator<<(ostream& os, const BigInteger& num);

  string num_;
};

ostream& operator<<(ostream& os, const BigInteger& num) {
  auto tmp = num.num_;
  reverse(tmp.begin(), tmp.end());
  os << tmp;
  return os;
}

int N, M;

bool done[101][101];
BigInteger cache[101][101];

void Solve(int n, int m) {
  if (done[n][m]) return;
  if (m == 0 || n == m) {
    done[n][m] = true;
    cache[n][m] = BigInteger("1");
    return;
  }

  done[n][m] = true;
  Solve(n - 1, m - 1);
  Solve(n - 1, m);
  cache[n][m] = cache[n - 1][m] + cache[n - 1][m - 1];
  return;
}

int main() {
  cin >> N >> M;
  Solve(N, M);
  cout << cache[N][M] << "\n";
  return 0;
}

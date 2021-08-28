//
// 43. Multiply Strings
// Problem: https://leetcode.com/problems/multiply-strings/
//

int Min(int x, int y) { return x < y ? x : y; }
int Max(int x, int y) { return x > y ? x : y; }
int Abs(int x) { return x < 0 ? -x : x; }

void Normalize(vector<int>& num) {
  num.push_back(0);
  for (int i = 0; i + 1 < num.size(); i++) {
    if (num[i] < 0) {
      int borrow = (Abs(num[i]) + 9) / 10;
      num[i + 1] -= borrow;
      num[i] += borrow * 10;
    } else {
      num[i + 1] += num[i] / 10;
      num[i] %= 10;
    }
  }
  while (num.size() > 1 && num.back() == 0) num.pop_back();
}

void AddTo(vector<int>& a, const vector<int>& b, int k) {
  a.resize(k + Max(a.size(), b.size()), 0);
  for (int i = 0; i < b.size(); i++) a[i + k] += b[i];
  Normalize(a);
}

void SubFrom(vector<int>& a, const vector<int>& b) {
  for (int i = 0; i < b.size(); i++) a[i] -= b[i];
  Normalize(a);
}

vector<int> Multiply(const vector<int>& a, const vector<int>& b) {
  vector<int> c(a.size() + b.size() + 1, 0);
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      c[i + j] += a[i] * b[j];
    }
  }
  Normalize(c);
  return c;
}

vector<int> Karatsuba(const vector<int>& a, const vector<int>& b) {
  int len_a = a.size();
  int len_b = b.size();

  if (len_a < len_b) return Karatsuba(b, a);
  if (len_a == 0 || len_b == 0) return vector<int>();

  if (len_a <= 10) return Multiply(a, b);
  int half = len_a / 2;

  vector<int> a0(a.begin(), a.begin() + half);
  vector<int> a1(a.begin() + half, a.end());
  vector<int> b0(b.begin(), b.begin() + Min(b.size(), half));
  vector<int> b1(b.begin() + Min(b.size(), half), b.end());

  vector<int> z2 = Karatsuba(a1, b1);
  vector<int> z0 = Karatsuba(a0, b0);

  AddTo(a0, a1, 0);
  AddTo(b0, b1, 0);

  vector<int> z1 = Karatsuba(a0, b0);
  SubFrom(z1, z0);
  SubFrom(z1, z2);

  vector<int> ret;
  AddTo(ret, z0, 0);
  AddTo(ret, z1, half);
  AddTo(ret, z2, half + half);
  return ret;
}

class Solution {
 public:
  string multiply(string num1, string num2) {
    vector<int> a, b;
    for (int i = num1.length() - 1; i >= 0; i--) a.push_back(num1[i] - '0');
    for (int i = num2.length() - 1; i >= 0; i--) b.push_back(num2[i] - '0');

    vector<int> ans_vec = Karatsuba(a, b);
    string ans = "";
    for (auto digit : ans_vec) {
      char chd = digit + '0';
      ans = chd + ans;
    }
    return ans;
  }
};
// 교환 
// https://www.acmicpc.net/problem/1039

#include <bits/stdc++.h>

using namespace std;

int n, k;
int dp[1000010][12];

int Digits2Num(const vector<int>& digits) {
  int num = 0;
  for (auto digit : digits) num = num * 10 + digit;
  return num;
}

int Solve(vector<int>& digits, int depth) {
  int num = Digits2Num(digits);
  if (depth == k) return num;
  if (dp[num][depth] != -1) return dp[num][depth];

  int num_digits = digits.size();
  int max_ret = 0;
  for (int i = 0; i < num_digits - 1; ++i) {
    for (int j = i + 1; j < num_digits; ++j) {
      if (i == 0 && digits[j] == 0) continue; // first digit
      swap(digits[i], digits[j]);
      max_ret = max(max_ret, Solve(digits, depth + 1));
      swap(digits[i], digits[j]);
    }
  }
  dp[num][depth] = max_ret;
  return dp[num][depth];
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n >> k;
  vector<int> digits;
  while (n > 0) {
    int digit = n % 10;
    digits.push_back(digit);
    n /= 10;
  }

  reverse(digits.begin(), digits.end());

  for (int i = 0; i <= 1000000; ++i)
    for (int j = 0; j <= 10; ++j)
      dp[i][j] = -1;

  int ans = Solve(digits, 0);
  cout << (ans == 0 ? -1 : ans) << "\n";

  return 0;
}
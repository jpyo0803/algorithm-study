// 박성원
// https://www.acmicpc.net/problem/1086

/*
  if answer is 0, print 0/1
  if answer if 1, print 1/1
  답은 기약분수로

  n = q * k + r, 0 <= r < n
*/

#include <bits/stdc++.h>

using namespace std;

long long p, q;
int n, k;
vector<string> nums;

long long dp[(1 << 15) + 5][105];  // keep remainder count
int ph_cnt_arr[(1 << 15) + 5];

int dp_rem_elem[16];
int dp_rem_pow10[1000];

long long Gcd(long long a, long long b) {
    if (b == 0) return a;
    return Gcd(b, a % b);
}

int ComputePow10Rem(int exp) {
  if (exp == 0) return 1;
  if (dp_rem_pow10[exp] != -1) return dp_rem_pow10[exp];

  int ret = ComputePow10Rem(exp / 2);
  ret *= ret;
  ret %= k;
  if (exp % 2) {
    ret *= 10;
    ret %= k;
  }

  dp_rem_pow10[exp] = ret;
  return ret;
}

int ComputeRemainder(const string& str) {
  int len = str.length();

  int carry = 0;
  for (int i = 0; i < len; ++i) {
    int num = (str[i] - '0') + carry * 10;
    carry = num % k;
  }
  return carry;
}

unsigned int Unset(unsigned int state, int idx) { return state & ~(1U << idx); }

long long Solve(unsigned int state, int rem) {
  if (dp[state][rem] != -1) return dp[state][rem];

  dp[state][rem] = 0;

  for (int i = 0; i < n; ++i) {
    if ((state >> i) & 0b1) {
      unsigned int prev_state = Unset(state, i);
      int ph_cnt = ph_cnt_arr[prev_state];
      int curr_rem = dp_rem_elem[i] * ComputePow10Rem(ph_cnt) % k;
      int prev_rem = rem - curr_rem;
      if (prev_rem < 0) prev_rem += k;
      auto cnt = Solve(prev_state, prev_rem);
      dp[state][rem] += cnt;
    }
  }
  return dp[state][rem];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    string ss;
    cin >> ss;
    nums.push_back(ss);
  }

  cin >> k;

  for (int i = 0; i < n; ++i) { // 15*50
    dp_rem_elem[i] = ComputeRemainder(nums[i]);
  }

  for (int i = 0; i < (1 << n); ++i) { // 2^15 * 100 = 3M
    for (int j = 0; j < k; ++j) {
      dp[i][j] = -1;
    }
  }

  for (int i = 0; i < n; ++i) { // 1500
    for (int j = 0; j < k; ++j) {
        dp[1 << i][j] = 0;
    }
  }

  for (int i = 0; i < n; ++i) { // 15
    dp[1 << i][dp_rem_elem[i]] = 1;
  }

  for (int i = 0; i < 1000; ++i) dp_rem_pow10[i] = -1;


  for (int i = 0; i < (1 << n); ++i) {
    int ph_cnt = 0;
    for (int j = 0; j < n; ++j) {
      if ((i >> j) & 0b1) {
        ph_cnt += nums[j].length();
      }
    }
    ph_cnt_arr[i] = ph_cnt;
  }

  q = 1;
  for (int i = 1; i <= n; ++i) {
    q *= i;
  }

  p = Solve((1 << n) - 1, 0);

  if (p == 0)
    cout << "0/1\n";
  else if (p == q)
    cout << "1/1\n";
  else {
    long long gcdd = Gcd(p, q);
    p /= gcdd;
    q /= gcdd;
    cout << p << "/" << q << "\n";
  }

  return 0;
}
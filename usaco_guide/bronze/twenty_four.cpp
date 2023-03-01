// Twenty-four (DMOJ)
// https://dmoj.ca/problem/ccc08s4

#include <bits/stdc++.h>

using namespace std;

int Eval(int a, int b, int op) {
  if (op == 0) {
    return a + b;
  } else if (op == 1) {
    return a - b;
  } else if (op == 2) {
    return a * b;
  } else {
    if (b == 0) return 1e9;
    if (a % b != 0) return 1e9;
    return a / b;
  }
  return 1e9;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  while (N--) {
    int ans = 0;

    vector<int> nums(4);
    for (int i = 0; i < 4; ++i) {
      cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    do {
      for (int i = 0; i < (1 << (2 * 3)); ++i) {
        vector<int> ops(3);
        for (int j = 0; j < 3; ++j) {
          ops[j] = (i >> (2 * j)) & 0x3;
        }

        bool ok = true;
        int cand = 0;
        cand = Eval(nums[0], nums[1], ops[0]);
        if (cand == 1e9) ok = false;
        cand = Eval(cand, nums[2], ops[1]);
        if (cand == 1e9) ok = false;
        cand = Eval(cand, nums[3], ops[2]);
        if (cand == 1e9) ok = false;
        if (ok) {
          if (cand <= 24) {
            ans = max(ans, cand);
          }
        }
        ok = true;
        int left = Eval(nums[0], nums[1], ops[0]);
        if (left == 1e9) ok = false;
        int right = Eval(nums[2], nums[3], ops[2]);
        if (right == 1e9) ok = false;
        if (ok) {
          cand = Eval(left, right, ops[1]);
          if (cand != 1e9) {
            if (cand <= 24) {
              ans = max(ans, cand);
            }
          }
        }
      }
    } while (next_permutation(nums.begin(), nums.end()));

    cout << ans << "\n";
  }

  return 0;
}

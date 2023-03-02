// Distinct Numbers (CSES)
// https://cses.fi/problemset/task/1621

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;
  vector<int> nums(N);
  for (int i = 0; i < N; ++i) {
    cin >> nums[i];
  }

  sort(nums.begin(), nums.end());

  int ans = 0;
  int lv = 0;
  for (auto e : nums) {
    if (e == lv) continue;
    ++ans;
    lv = e;
  }

  cout << ans << "\n";

  return 0;
}
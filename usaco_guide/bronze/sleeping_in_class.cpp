// Sleeping in Class (Bronze)
// http://usaco.org/index.php?page=viewproblem2&cpid=1203

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    vector<int> nums(N);

    int sum = 0;
    for (int i = 0; i < N; ++i) {
      cin >> nums[i];
      sum += nums[i];
    }

    if (sum == 0) {
      cout << 0 << "\n";
      continue;
    }

    for (int d = 1; d <= sum; ++d) {
      if (sum % d != 0) continue;  // not divisible

      bool ok = true;
      int acc = 0;
      for (int j = 0; j < N; ++j) {
        acc += nums[j];
        if (acc == d) {
          acc = 0;
        } else if (acc > d) {
          ok = false;
          break;
        }
      }
      if (!ok) continue;
      cout << N - (sum / d) << "\n";
      break;
    }
  }

  return 0;
}
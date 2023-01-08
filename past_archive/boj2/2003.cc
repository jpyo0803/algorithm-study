//
// Sum of Numbers 2
// Problem: https://www.acmicpc.net/problem/2003
//

#include <iostream>

using namespace std;

const int MAX{10000};
int N, M;
int nums[MAX];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }

  int ans{0};
  int sum{0};
  int i{0}, j{-1};
  while (i < N && j < N) {
    if (sum < M) {
      sum += nums[++j];
    } else if (sum > M) {
      sum -= nums[i++];
    } else {
      ans += 1;
      sum -= nums[i++];
    }
  }
  cout << ans;

  return 0;
}
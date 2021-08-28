//
// Sum of GCD
// Problem: https://www.acmicpc.net/problem/9613
//

#include <iostream>

using namespace std;
int T, N;
int nums[100];

int findGCD(int x, int y) {
  int larger = (x > y) ? x : y;
  int smaller = (larger == x) ? y : x;

  int rem = larger % smaller;
  while (rem != 0) {
    larger = smaller;
    smaller = rem;
    rem = larger % smaller;
  }
  return smaller;
}

int main() {
  cin >> T;
  for (int tc = 0; tc < T; tc++) {
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> nums[i];
    }
    int64_t ans = 0;
    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j < N; j++) {
        ans += findGCD(nums[i], nums[j]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
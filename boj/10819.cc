//
// Make the difference largest
// Problem: https://www.acmicpc.net/problem/10819
//

#include <cmath>
#include <iostream>

using namespace std;
const int MAX_SIZE{8};
int N;
int nums[MAX_SIZE];
int chosen[MAX_SIZE];
bool used[MAX_SIZE];

int ans = 0;
void perm(int num_chosen) {
  if (num_chosen == N) {
    int candidate = 0;
    for (int i = 0; i < N - 1; i++) {
      candidate += abs(nums[chosen[i]] - nums[chosen[i + 1]]);
    }
    if (ans < candidate) {
      ans = candidate;
    }
    return;
  }

  for (int i = 0; i < N; i++) {
    if (!used[i]) {
      used[i] = true;
      chosen[num_chosen] = i;
      perm(num_chosen + 1);
      used[i] = false;
    }
  }
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> nums[i];
  }
  perm(0);
  cout << ans;
  return 0;
}

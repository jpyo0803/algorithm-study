//
// Router Installation
// Problem: https://www.acmicpc.net/problem/2110
//

#include <algorithm>
#include <cstdio>

using namespace std;
constexpr int MAX = 200000;

int N, C, ans{0};
int houses[MAX];

bool IsValid(int candidate) {
  int num_to_assign = C;
  int prev_assigned_num = -1000000000;
  for (int i = 0; i < N; i++) {
    if (houses[i] - prev_assigned_num >= candidate) {
      num_to_assign -= 1;
      if (num_to_assign == 0) {
        return true;
      }
      prev_assigned_num = houses[i];
    }
  }
  return false;
}

void BinarySearch(int l, int r) {
  if (l > r) return;
  int mid = (l + r) / 2;
  if (IsValid(mid)) {
    ans = mid;
    BinarySearch(mid + 1, r);
  } else {
    BinarySearch(l, mid - 1);
  }
}

int main() {
  scanf("%d%d", &N, &C);
  for (int i = 0; i < N; i++) {
    scanf("%d", &houses[i]);
  }

  sort(houses, houses + N);

  BinarySearch(1, houses[N - 1] - houses[0]);

  printf("%d", ans);
  return 0;
}

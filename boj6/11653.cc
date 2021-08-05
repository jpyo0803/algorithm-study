// 소인수분해
// https://www.acmicpc.net/problem/11653

#include <math.h>
#include <stdio.h>

#include <vector>

using namespace std;

int N;

vector<int> Solve(int n) {
  vector<int> factors;
  int sqrt_n = sqrt(n);
  for (int i = 2; i <= sqrt_n; i++) {
    while (n % i == 0) {
      factors.push_back(i);
      n /= i;
    }
  }
  if (n != 1) factors.push_back(n);
  return factors;
}

int main() {
  scanf("%d", &N);
  auto ans = Solve(N);
  if (!ans.empty()) {
    for (auto e : ans) printf("%d\n", e);
  }
  return 0;
}

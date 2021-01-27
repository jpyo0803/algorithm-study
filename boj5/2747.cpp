//
// 피보나치 수
// Link: https://www.acmicpc.net/problem/2747
//

#include <cstdio>

using namespace std;

int n;

int cache[46];

int Fibonacci(int x) {
  if (x < 2) return x;
  int& ret = cache[x];
  if (ret != 0) return ret;

  ret = Fibonacci(x - 1) + Fibonacci(x - 2);
  return ret;
}

int main() {
  scanf("%d", &n);
  printf("%d\n", Fibonacci(n));
  return 0;
}

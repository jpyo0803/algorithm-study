//
// Waterbottle Problem
// Problem: https://www.acmicpc.net/problem/14881
//

#include <cstdio>

using namespace std;
int T, x, y, z;

int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  scanf("%d", &T);
  for (int tc = 0; tc < T; tc++) {
    scanf("%d%d%d", &x, &y, &z);
    int larger = x > y ? x : y;
    if (larger < z) {
      printf("NO\n");
      continue;
    }
    int smaller = (x + y) - larger;
    int v = gcd(larger, smaller);
    if (z % v == 0)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}

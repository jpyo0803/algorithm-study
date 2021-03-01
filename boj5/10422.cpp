//
// 괄호
// Link: https://www.acmicpc.net/problem/10422
//

#include <cstdint>
#include <cstdio>

constexpr uint64_t kMod = 1000000007;
int T, L;

uint64_t cache[5001];

uint64_t Catalan(int x) {
  uint64_t& ret = cache[x];
  if (ret != 0) return ret;
  for (int a = 0; a <= x - 2; a += 2) {
    int b = x - 2 - a;
    ret += (Catalan(a) * Catalan(b)) % kMod;
    ret %= kMod;
  }
  return ret;
}

int main() {
  cache[0] = cache[2] = 1;
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d", &L);
    if (L % 2)
      printf("0\n");
    else
      printf("%llu\n", Catalan(L));
  }
  return 0;
}

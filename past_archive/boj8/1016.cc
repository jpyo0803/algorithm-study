// 제곱 ㄴㄴ 수
// https://www.acmicpc.net/problem/1016

#include <math.h>
#include <stdio.h>

using namespace std;

constexpr int kMax = 1000000;

long long minimum, maximum;

bool is_not_prime[kMax + 1];
bool is_crossed_out[kMax + 1];

void ErastothenesSieve() {
  int sqrt_n = static_cast<int>(sqrt(kMax));

  is_not_prime[0] = is_not_prime[1] = true;
  for (int i = 2; i <= sqrt_n; i++) {
    if (!is_not_prime[i]) {
      for (int j = i * i; j <= kMax; j += i) {
        is_not_prime[j] = true;
      }
    }
  }
}

long long Solve(long long minimum, long long maximum) {
  ErastothenesSieve();

  long long count = 0;
  for (long long i = 2; i * i <= maximum; i++) {
    if (is_not_prime[i]) continue;

    long long sqr_i = i * i;
    long long j = minimum / sqr_i;
    if (minimum % sqr_i) j++;

    while (j * sqr_i <= maximum) {
      if (!is_crossed_out[j * sqr_i - minimum]) {
        is_crossed_out[j * sqr_i - minimum] = true;
        count++;
      }
      j++;
    }
  }
  return maximum - minimum + 1 - count;
}

int main() {
  scanf("%lld%lld", &minimum, &maximum);

  printf("%lld\n", Solve(minimum, maximum));
  return 0;
}

// 피보나치 수 6
// https://www.acmicpc.net/problem/11444

#include <stdint.h>
#include <stdio.h>

constexpr int64_t kMod = 1000000007;

int64_t N;

struct Matrix22 {
  Matrix22() = default;
  Matrix22(int64_t e00, int64_t e01, int64_t e10, int64_t e11) {
    data[0][0] = e00;
    data[0][1] = e01;
    data[1][0] = e10;
    data[1][1] = e11;
  }
  Matrix22 operator*(const Matrix22& other) {
    Matrix22 res;
    res.data[0][0] =
        data[0][0] * other.data[0][0] + data[0][1] * other.data[1][0];
    res.data[0][1] =
        data[0][0] * other.data[0][1] + data[0][1] * other.data[1][1];
    res.data[1][0] =
        data[1][0] * other.data[0][0] + data[1][1] * other.data[1][0];
    res.data[1][1] =
        data[1][0] * other.data[0][1] + data[1][1] * other.data[1][1];
    res.data[0][0] %= kMod;
    res.data[0][1] %= kMod;
    res.data[1][0] %= kMod;
    res.data[1][1] %= kMod;
    return res;
  }
  int64_t data[2][2];
};

Matrix22 base_case(1, 1, 1, 0);

Matrix22 Solve(int64_t n) {
  if (n == 0 || n == 1) return base_case;
  auto res = Solve(n / 2);
  res = res * res;
  if (n % 2) res = res * base_case;
  return res;
}

int main() {
  scanf("%lld", &N);
  if (N == 0) {
    printf("0\n");
    return 0;
  }
  auto res = Solve(N - 1);
  printf("%lld\n", res.data[0][0]);
  return 0;
}
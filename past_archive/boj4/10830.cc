//
// Matrix Square
// Link: https://www.acmicpc.net/problem/10830
//

#include <cstdint>
#include <cstdio>

constexpr int MOD = 1000;

int N;
int64_t B;

class SquareMatrix {
 public:
  int arr[5][5];
  int size = N;
  SquareMatrix(int _size) : size(_size){};

  SquareMatrix Idendity() const {
    SquareMatrix ret(size);
    for (int i = 0; i < ret.size; i++) {
      for (int j = 0; j < ret.size; j++) {
        ret.arr[i][j] = (i == j);
      }
    }
    return ret;
  }

  SquareMatrix operator*(const SquareMatrix& other) {
    SquareMatrix ret(size);
    for (int i = 0; i < ret.size; i++) {
      for (int j = 0; j < ret.size; j++) {
        ret.arr[i][j] = 0;
        for (int k = 0; k < ret.size; k++) {
          ret.arr[i][j] += ((arr[i][k] % MOD) * (other.arr[k][j] % MOD)) % MOD;
        }
        ret.arr[i][j] %= MOD;
      }
    }
    return ret;
  }
};

SquareMatrix Pow(const SquareMatrix& A, int64_t b) {
  if (b == 0) return A.Idendity();
  if (b % 2) return Pow(A, b - 1) * A;
  SquareMatrix half = Pow(A, b / 2);
  return half * half;
}

int main() {
  scanf("%d%lld", &N, &B);
  SquareMatrix A(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &A.arr[i][j]);
    }
  }

  SquareMatrix ans = Pow(A, B);
  for (int i = 0; i < ans.size; i++) {
    for (int j = 0; j < ans.size; j++) {
      printf("%d ", ans.arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}

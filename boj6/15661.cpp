// 링크와 스타트
// https://www.acmicpc.net/problem/15661

#include <stdio.h>

#include <vector>

using namespace std;

int N;
int table[20][20];

int Min(int x, int y) { return x < y ? x : y; }
int Abs(int x) { return x < 0 ? -x : x; }

int ans = 987654321;
bool assigned[20];  // true = A, false = B

vector<int> A, B;

void Solve(int nth) {
  if (nth == N) {
    A.clear();
    B.clear();
    for (int i = 0; i < N; i++) {
      if (assigned[i])
        A.push_back(i);
      else
        B.push_back(i);
    }
    if (A.empty() || B.empty()) return;

    int sum_a = 0, sum_b = 0;
    int len_a = A.size(), len_b = B.size();
    for (int i = 0; i < len_a; i++) {
      for (int j = i + 1; j < len_a; j++) {
        sum_a += (table[A[i]][A[j]] + table[A[j]][A[i]]);
      }
    }

    for (int i = 0; i < len_b; i++) {
      for (int j = i + 1; j < len_b; j++) {
        sum_b += (table[B[i]][B[j]] + table[B[j]][B[i]]);
      }
    }
    ans = Min(ans, Abs(sum_a - sum_b));
    return;
  }

  Solve(nth + 1);  // assign B
  assigned[nth] = true;
  Solve(nth + 1);  // assign A
  assigned[nth] = false;
}

int main() {
  scanf("%d", &N);
  A.reserve(N);
  B.reserve(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &table[i][j]);
    }
  }

  Solve(0);
  printf("%d\n", ans);

  return 0;
}

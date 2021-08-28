//
// 4 Integers with zero sum
// Problem: https://www.acmicpc.net/problem/7453
//

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
const int MAX{4000};
int N;
int A[MAX];
int B[MAX];
int C[MAX];
int D[MAX];

void two_arr_add(vector<int>& vec, int A[], int B[], int sz) {
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      vec.push_back(A[i] + B[j]);
    }
  }
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    scanf("%d%d%d%d", &A[i], &B[i], &C[i], &D[i]);
  }

  vector<int> AB, CD;
  two_arr_add(AB, A, B, N);
  two_arr_add(CD, C, D, N);

  sort(AB.begin(), AB.end());
  sort(CD.begin(), CD.end());

  int i{0}, j{(int)CD.size() - 1};

  uint64_t ans{0};
  while (i < AB.size() && j >= 0) {
    int sum = AB[i] + CD[j];
    if (sum < 0) {
      i++;
    } else if (sum > 0) {
      j--;
    } else {
      uint64_t ci{1};
      while (i + 1 < AB.size() && AB[i + 1] == AB[i]) {
        ci += 1;
        i++;
      }
      uint64_t cj{1};
      while (j - 1 >= 0 && CD[j - 1] == CD[j]) {
        cj += 1;
        j--;
      }
      ans += ci * cj;
      i++;
      j--;
    }
  }

  cout << ans;

  return 0;
}

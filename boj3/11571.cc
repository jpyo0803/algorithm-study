//
// Fraction to Decimal
// Link: https://www.acmicpc.net/problem/11571
//

#include <cstdio>
#include <vector>

using namespace std;

constexpr int kMaxSize = 1024;
int T, num, den;
vector<int> decimals;

int Conversion(int rem, int den) {
  int frequency_table[kMaxSize];
  for (int i = 0; i < kMaxSize; i++) frequency_table[i] = -1;
  decimals.clear();
  int idx = 0;
  while (num > 0) {
    if (frequency_table[rem] != -1) return frequency_table[rem];

    int num = rem * 10;
    decimals.push_back(num / den);
    frequency_table[rem] = idx++;
    rem = num % den;
  }
  decimals.push_back(0);
  return idx;
}

int main() {
  scanf("%d", &T);
  for (int t = 0; t < T; t++) {
    scanf("%d%d", &num, &den);
    printf("%d.", num / den);
    int parent_idx = Conversion(num % den, den);
    for (int i = 0; i < decimals.size(); i++) {
      if (i == parent_idx) printf("(");
      printf("%d", decimals[i]);
    }
    printf(")\n");
  }

  return 0;
}

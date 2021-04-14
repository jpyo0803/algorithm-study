//
// Base Conversion
// Link: https://www.acmicpc.net/problem/11576
//

#include <stdio.h>

#include <vector>

int A, B;
int num_digit;
int dec = 0;

int main() {
  scanf("%d%d%d", &A, &B, &num_digit);
  int digit;
  for (int i = num_digit - 1; i >= 0; i--) {
    scanf("%d", &digit);
    dec = dec * A + digit;
  }

  std::vector<int> ans;

  while (dec > 0) {
    ans.push_back(dec % B);
    dec /= B;
  }

  for (auto rev_it = ans.rbegin(); rev_it != ans.rend(); rev_it++) {
    printf("%d ", *rev_it);
  }
  printf("\n");

  return 0;
}

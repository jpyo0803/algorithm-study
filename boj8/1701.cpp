// Cubeditor
// https://www.acmicpc.net/problem/1701

#include <stdio.h>
#include <string.h>

char S[5010];
int pi_table[5010];

int Max(int x, int y) { return x < y ? y : x; }

int KMP(char* key, int length) {
  for (int i = 0; i < length; ++i) {
    pi_table[i] = 0;
  }

  int max_val = 0;
  int begin = 1, matched = 0;
  while (begin + matched < length) {
    if (key[begin + matched] == key[matched]) {
      ++matched;
      max_val = Max(max_val, matched);
      pi_table[begin + matched - 1] = matched;
    } else {
      if (matched == 0) {
        ++begin;
      } else {
        begin += matched - pi_table[matched - 1];
        matched = pi_table[matched - 1];
      }
    }
  }
  return max_val;
}

int Solve() {
  const int sl = strlen(S);
  int ans = 0;
  for (int i = 0; i < sl; ++i) {
    ans = Max(ans, KMP(S + i, sl - i));
  }
  return ans;
}

int main() {
  scanf("%s", S);
  printf("%d\n", Solve());
  return 0;
}
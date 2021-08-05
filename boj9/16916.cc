// 부분 문자열
// https://www.acmicpc.net/problem/16916

#include <stdio.h>
#include <string.h>

char S[1000010];
char P[1000010];
int pi_table[1000010];

int s_length, p_length;

void GeneratePiTable() {
  int matched = 0, begin = 1;

  while (begin + matched < p_length) {
    if (P[matched] == P[begin + matched]) {
      ++matched;
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
}

int Solve() {
  GeneratePiTable();

  int matched = 0, begin = 0;
  while (begin <= s_length - p_length) {
    if (matched < p_length && S[begin + matched] == P[matched]) {
      ++matched;
      if (p_length == matched) {
        return 1;
      }
    } else {
      if (matched == 0) {
        ++begin;
      } else {
        begin += matched - pi_table[matched - 1];
        matched = pi_table[matched - 1];
      }
    }
  }
  return 0;
}

int main() {
  scanf("%s%s", S, P);
  s_length = strlen(S);
  p_length = strlen(P);

  printf("%d\n", Solve());
  return 0;
}
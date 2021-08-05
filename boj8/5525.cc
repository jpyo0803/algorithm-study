// IOIOI
// https://www.acmicpc.net/problem/5525

#include <stdio.h>

int N, M;
char haystack[1000010];
char needle[1000010];
int pi_table[1000010];

void GeneratePiTable() {
  const int needle_length = 2 * N + 1;
  int pivot = 1, matched = 0;
  while (pivot + matched < needle_length) {
    if (needle[pivot + matched] == needle[matched]) {
      ++matched;
      pi_table[pivot + matched - 1] = matched;
    } else {
      if (matched == 0) {
        ++pivot;
      } else {
        pivot += matched - pi_table[matched - 1];
        matched = pi_table[matched - 1];
      }
    }
  }
}

int Solve() {
  GeneratePiTable();

  const int needle_length = 2 * N + 1;
  int ans = 0;

  int pivot = 0, matched = 0;
  while (pivot <= M - needle_length) {
    if (matched < needle_length &&
        haystack[pivot + matched] == needle[matched]) {
      matched++;
      if (matched == needle_length) {
        ++ans;
      }
    } else {
      if (matched == 0) {
        ++pivot;
      } else {
        pivot += matched - pi_table[matched - 1];
        matched = pi_table[matched - 1];
      }
    }
  }
  return ans;
}

int main() {
  scanf("%d%d%s", &N, &M, haystack);
  char ch = 'I';
  for (int i = 0; i < N * 2 + 1; ++i) {
    needle[i] = ch;
    if (ch == 'I')
      ch = 'O';
    else
      ch = 'I';
  }
  printf("%d\n", Solve());
  return 0;
}
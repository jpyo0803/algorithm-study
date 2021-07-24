// 행복한지 슬픈지
// https://www.acmicpc.net/problem/10769

#include <stdio.h>
#include <string.h>

char haystack[260];

constexpr int kFaceLength = 3;
int N;
char happy_face[3] = {':', '-', ')'};
char sad_face[3] = {':', '-', '('};

void Solve() {
  int happy_count = 0, sad_count = 0;

  int pivot = 0, matched = 0;
  while (pivot <= N - kFaceLength) {
    if (matched < kFaceLength &&
        haystack[pivot + matched] == happy_face[matched]) {
      ++matched;
      if (matched == kFaceLength) {
        ++happy_count;
      }
    } else {
      if (matched == 0) {
        pivot++;
      } else {
        pivot += matched;
        matched = 0;
      }
    }
  }

  pivot = matched = 0;

  while (pivot <= N - kFaceLength) {
    if (matched < kFaceLength &&
        haystack[pivot + matched] == sad_face[matched]) {
      ++matched;
      if (matched == kFaceLength) {
        ++sad_count;
      }
    } else {
      if (matched == 0) {
        pivot++;
      } else {
        pivot += matched;
        matched = 0;
      }
    }
  }
  if (happy_count == 0 && sad_count == 0) {
    printf("none\n");
  } else if (happy_count == sad_count) {
    printf("unsure\n");
  } else if (happy_count > sad_count) {
    printf("happy\n");
  } else {
    printf("sad\n");
  }
}

int main() {
  int i = 0;
  while (true) {
    int ch = getchar();
    if (ch == EOF) break;
    haystack[i++] = static_cast<char>(ch);
  }
  haystack[i] = '\0';
  N = strlen(haystack);
  Solve();
  return 0;
}
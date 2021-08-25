// 에디터
// https://www.acmicpc.net/problem/1406

#include <stdio.h>
#include <string.h>

#include <stack>

using namespace std;

char input[100'010];

int N;

stack<char> left, right;

int main() {
  scanf("%s %d", input, &N);
  getchar();

  size_t len = strlen(input);
  for (size_t i = 0; i < len; ++i) {
    left.push(input[i]);
  }

  for (int n = 0; n < N; ++n) {
    char c;
    scanf("%c", &c);
    getchar();
    if (c == 'P') {
      char d;
      scanf("%c", &d);
      getchar();
      left.push(d);
    } else {
      if (c == 'L') {
        if (!left.empty()) {
          right.push(left.top());
          left.pop();
        }
      } else if (c == 'D') {
        if (!right.empty()) {
          left.push(right.top());
          right.pop();
        }
      } else if (c == 'B') {
        if (!left.empty()) {
          left.pop();
        }
      }
    }
  }

  while (!left.empty()) {
    right.push(left.top());
    left.pop();
  }

  while (!right.empty()) {
    printf("%c", right.top());
    right.pop();
  }
  printf("\n");
  return 0;
}
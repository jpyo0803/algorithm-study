// 좋은 단어
// https://www.acmicpc.net/problem/3986

#include <stdio.h>
#include <string.h>

#include <stack>

using namespace std;

int N;
char line[100002];

int main() {
  scanf("%d", &N);
  int num_good_word = 0;
  for (int n = 0; n < N; n++) {
    scanf("%s", line);
    int len = strlen(line);
    if (len % 2) continue;

    stack<char> stk;
    for (int i = 0; i < len; i++) {
      char ch = line[i];
      bool found_match = false;
      while (!stk.empty() && stk.top() == ch) {
        stk.pop();
        found_match = true;
      }
      if (!found_match) stk.push(ch);
    }
    if (stk.empty()) num_good_word++;
  }
  printf("%d\n", num_good_word);
  return 0;
}

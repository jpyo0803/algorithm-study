// PPAP
// https://www.acmicpc.net/problem/16120

#include <stdio.h>
#include <string.h>

#include <stack>

using namespace std;

char input[1'000'010];
char ppap[4] = {'P', 'P', 'A', 'P'};
int len;

stack<char> stk, stk2;

void Solve() {
  for (int i = 0; i < len; ++i) {
    stk.push(input[i]);
  }

  bool is_success = true;

  while (is_success && stk.size() > 1) {
    int i = 3;
    while (!stk.empty() && stk.top() == ppap[i]) {
      stk2.push(stk.top());
      stk.pop();
      --i;
    }

    if (i == 0) {
      if (stk.size() == 0) {
        is_success = false;
        break;
      }
      stk.push('P');
      stk2.pop();
    } else if (i == -1) {
      for (int j = 0; j < 4; ++j) {
        stk2.pop();
      }
      stk.push('P');
      int j = 2;
      while (!stk2.empty() && j > 0) {
        stk.push(stk2.top());
        stk2.pop();
        --j;
      }
    } else {
      is_success = false;
    }
  }

  if (is_success) {
    if (stk.size() == 1) {
      if (stk.top() == 'A') {
        is_success = false;
      } else if (!stk2.empty()) {
        is_success = false;
      }
    }
  }
  printf("%s\n", is_success ? "PPAP" : "NP");
}

int main() {
  scanf("%s", input);
  len = strlen(input);
  Solve();

  return 0;
}
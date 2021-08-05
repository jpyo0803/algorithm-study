//
// 괄호 추가하기
// Link: https://www.acmicpc.net/problem/16637
//

#include <cstdio>
#include <string>

using namespace std;

constexpr int NINF = -987654321;

int Char2Int(char a) { return a - '0'; }
int Max(int x, int y) { return x > y ? x : y; }

int N, ans = NINF;

int numbers[10];
char op[10];
bool assign[10];

void DFS(int nth) {
  if (nth >= N / 2) {
    int numbers_copy[N / 2 + 1];
    for (int i = 0; i < N / 2 + 1; i++) numbers_copy[i] = numbers[i];

    for (int i = 0; i < nth; i++) {
      if (assign[i]) {
        if (op[i] == '+') {
          numbers_copy[i] += numbers_copy[i + 1];
        } else if (op[i] == '-') {
          numbers_copy[i] -= numbers_copy[i + 1];
        } else if (op[i] == '*') {
          numbers_copy[i] *= numbers_copy[i + 1];
        }
        numbers_copy[i + 1] = 0;
      }
    }

    int res = numbers_copy[0];
    for (int i = 0; i < nth; i++) {
      if (!assign[i]) {
        if (op[i] == '+') {
          res += numbers_copy[i + 1];
        } else if (op[i] == '-') {
          res -= numbers_copy[i + 1];
        } else if (op[i] == '*') {
          res *= numbers_copy[i + 1];
        }
      }
    }
    ans = Max(ans, res);
    return;
  }

  assign[nth] = false;
  DFS(nth + 1);
  assign[nth] = true;
  assign[nth + 1] = false;
  DFS(nth + 2);
}

int main() {
  char expression[21];
  scanf("%d%s", &N, expression);
  for (int i = 0; i < N; i++) {
    if (i % 2) op[i / 2] = expression[i];
    else numbers[i / 2] = Char2Int(expression[i]);
  }

  DFS(0);
  printf("%d\n", ans);

  return 0;
}
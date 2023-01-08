//
// Water Bottle
// Problem: https://www.acmicpc.net/problem/2251
//

#include <iostream>

using namespace std;
const int MAX{200};
int A, B, C;
bool visited[MAX + 1][MAX + 1];
bool ans[MAX + 1];

void dfs(int a, int b, int c) {
  if (!visited[a][b]) {
    visited[a][b] = true;
    if (a == 0) ans[c] = true;

    if (B - b < a)
      dfs(a - (B - b), B, c);
    else
      dfs(0, b + a, c);

    if (C - c < a)
      dfs(a - (C - c), b, C);
    else
      dfs(0, b, c + a);

    if (A - a < b)
      dfs(A, b - (A - a), c);
    else
      dfs(a + b, 0, c);

    if (C - c < b)
      dfs(a, b - (C - c), C);
    else
      dfs(a, 0, c + b);

    if (A - a < c)
      dfs(A, b, c - (A - a));
    else
      dfs(a + c, b, 0);

    if (B - b < c)
      dfs(a, B, c - (B - b));
    else
      dfs(a, b + c, 0);
  }
}

int main() {
  cin >> A >> B >> C;
  dfs(0, 0, C);
  for (int i = 0; i <= C; i++) {
    if (ans[i]) {
      cout << i << " ";
    }
  }
  return 0;
}

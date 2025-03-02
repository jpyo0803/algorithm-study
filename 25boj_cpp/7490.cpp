// 0 만들기
// https://www.acmicpc.net/problem/7490

#include <bits/stdc++.h>

using namespace std;

int t, n;

int vv[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
char op_type[3] = {' ', '+', '-'};
char ops[10];

bool Evaluate() {
  int result = 0;
  int acc = vv[0];

  char last_op = '+';

  for (int i = 0; i < n - 1; ++i) {
    if (ops[i] == ' ') {
      acc *= 10;
      acc += vv[i + 1];
    } else {
      if (last_op == '+') {
        result += acc;
      } else if (last_op == '-') {
        result -= acc;
      }
      acc = vv[i + 1];
      last_op = ops[i];
    }
  // cout << "result = " << result << " / "  << acc << endl;
  }

  if (last_op == '+') {
    result += acc;
  } else {
    result -= acc;
  }
  // cout << "result = " << result << endl;
  return result == 0;
}

void Solve(int depth) {
  if (depth == n - 1) {
    // for (int i = 0; i < n - 1; ++i) {
    //   cout << ops[i];
    // }
    // cout << endl;
    if (Evaluate()) {
      cout << vv[0];
      for (int i = 0; i < n - 1; ++i) {
        cout << ops[i] << vv[i + 1];
      }
      cout << "\n";
    }
    return;
  }

  for (int i = 0; i < 3; ++i) {
    ops[depth] = op_type[i];
    Solve(depth + 1);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;

  while (t--) {
    cin >> n;
    Solve(0);
    cout << "\n";
  }

  return 0;
}
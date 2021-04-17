// 문자열
// https://www.acmicpc.net/problem/1120

#include <iostream>
#include <string>

using namespace std;

int ans = 987654321;

int Min(int x, int y) { return x < y ? x : y; }

int FindDiff(const string& a, const string& b) {
  int len = Min(a.size(), b.size());
  int diff = 0;
  for (int i = 0; i < len; i++) {
    if (a[i] == '*') continue;
    if (a[i] != b[i]) diff++;
  }
  return diff;
}

void Solve(string a, string b) {
  string tmp = a;
  while (tmp.size() <= b.size()) {
    ans = Min(ans, FindDiff(tmp, b));
    tmp = '*' + tmp;
  }
}

int main() {
  string A, B;
  cin >> A >> B;

  Solve(A, B);
  cout << ans << endl;

  return 0;
}

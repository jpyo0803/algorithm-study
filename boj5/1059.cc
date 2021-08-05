#include <algorithm>
#include <iostream>

using namespace std;

int L, n;
int S[51];

int GetCombinatorics(int x, int y) {
  int d = y - x;
  if (d <= 2) return 0;
  return (d - 1) * (d - 2) / 2;
}

int main() {
  S[0] = 0;
  cin >> L;
  for (int i = 1; i <= L; i++) cin >> S[i];
  cin >> n;

  sort(S, S + L + 1);

  int result = 0;
  for (int i = 1; i <= L; i++) {
    int A = S[i - 1];
    int B = S[i];
    if (n > A && n < B) {
      result = GetCombinatorics(A, B) - GetCombinatorics(A, n) -
               GetCombinatorics(n, B);
    }
  }
  cout << result << endl;
  return 0;
}

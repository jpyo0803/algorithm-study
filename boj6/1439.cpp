//
// 뒤집기
// Link: https://www.acmicpc.net/problem/1439
//

#include <iostream>

using namespace std;

int Solve(string& S) {
  char pivot = S[0];
  S.push_back(pivot);

  int diff_count = 0;
  for (int i = 0; i < S.size();) {
    if (S[i] != pivot) {
      diff_count++;
      while (S[++i] != pivot)
        ;
    } else {
      i++;
    }
  }
  return diff_count;
}

int main() {
  string S;
  cin >> S;
  cout << Solve(S) << endl;

  return 0;
}

// 세준세비
// https://www.acmicpc.net/problem/1524

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
      cin >> B[i];
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int i = 0, j = 0;
    while (i < N && j < M) {
      if (A[i] < B[j]) { // kill A
        i++;
      } else if (A[i] > B[j]) {
        j++;
      } else { // same
        j++; // skill B
      }
    }
    if (j == M) {
      cout << "S\n";
    } else {
      cout << "B\n";
    }
  }
  return 0;
}
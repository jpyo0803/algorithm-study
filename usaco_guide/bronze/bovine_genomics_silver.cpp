// Bovine Genomics (Silver)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=739

#include <bits/stdc++.h>

using namespace std;

int G2E(char c) {
  if (c == 'A')
    return 0;
  else if (c == 'C')
    return 1;
  else if (c == 'G')
    return 2;
  return 3;  // c == 'T'
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<string> spotty(N), plain(N);
  for (int i = 0; i < N; ++i) {
    cin >> spotty[i];
  }

  for (int i = 0; i < N; ++i) {
    cin >> plain[i];
  }

  int ans = 0;
  for (int i = 0; i < M - 2; ++i) {        // 50
    for (int j = i + 1; j < M - 1; ++j) {  // 2500
      for (int k = j + 1; k < M; ++k) {    // generate triplet, 125,000
        bool exist_arr[64]{};

        for (int l = 0; l < N; ++l) {
          exist_arr[4 * 4 * G2E(spotty[l][i]) + 4 * G2E(spotty[l][j]) +
                    G2E(spotty[l][k])] = true;
        }

        bool ok = true;
        for (int l = 0; l < N; ++l) {
          int x = 4 * 4 * G2E(plain[l][i]) + 4 * G2E(plain[l][j]) +
                  G2E(plain[l][k]);
          if (exist_arr[x]) {
            ok = false;
            break;
          }
        }
        if (ok) ++ans;
      }
    }
  }
  cout << ans << "\n";

  return 0;
}
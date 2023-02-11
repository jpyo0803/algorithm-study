// Guess the Animal (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=893

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<set<string>> animals(N);

  for (int i = 0; i < N; ++i) {
    string A;
    int K;
    cin >> A >> K;

    for (int j = 0; j < K; ++j) {
      string B;
      cin >> B;
      animals[i].insert(B);
    }
  }

  int ans = 0;
  for (int i = 0; i < N - 1; ++i) {
    for (int j = i + 1; j < N; ++j) {  // ordered pair of cows
      int sc = 0;
      for (auto& a : animals[i]) {
        if (animals[j].find(a) != animals[j].end()) {
          sc++;
        }
      }
      ans = max(ans, sc);
    }
  }

  cout << ans + 1 << "\n";

  return 0;
}
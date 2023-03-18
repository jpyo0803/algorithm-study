// Jury Marks (CF)
// https://codeforces.com/contest/831/problem/C

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int K, N;
  cin >> K >> N;

  vector<int> ps(K), b(N);
  for (int i = 0; i < K; ++i) {
    cin >> ps[i];
    if (i > 0) {
      ps[i] += ps[i - 1];
    }
  }

  for (int i = 0; i < N; ++i) {
    cin >> b[i];
  }

  vector<int> cand;
  for (int i = 0; i < K; ++i) {
    cand.push_back(b[0] - ps[i]);
  }

  sort(cand.begin(), cand.end());
  cand.erase(unique(cand.begin(), cand.end()), cand.end());

  int ans = 0;

  for (auto e : cand) {
    set<int> c;
    for (int i = 0; i < K; ++i) {
      c.insert(e + ps[i]);
    }
    bool ok = true;
    for (int i = 0; i < N; ++i) {
      auto it = c.find(b[i]);
      if (it == c.end()) {
        ok = false;
        break;
      }
    }
    if (ok) ++ans;
  }

  cout << ans << "\n";

  return 0;
}

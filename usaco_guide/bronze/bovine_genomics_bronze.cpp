// Bovine Genomics (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=736

#include <bits/stdc++.h>

using namespace std;

int Seq2Idx(char s) {
  if (s == 'A')
    return 0;
  else if (s == 'C')
    return 1;
  else if (s == 'G')
    return 2;
  return 3;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M;
  cin >> N >> M;

  vector<string> s(N), p(N);
  for (int i = 0; i < N; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 0; i < M; ++i) {
    int s_cnt[4]{};
    int p_cnt[4]{};

    for (int j = 0; j < N; ++j) {
      ++s_cnt[Seq2Idx(s[j][i])];
      ++p_cnt[Seq2Idx(p[j][i])];
    }

    // Check if overlapping gene type exists.
    // If exist, given the overlapping, you cannot tell
    bool ok = true;
    for (int j = 0; j < 4; ++j) {
      if (s_cnt[j] > 0 && p_cnt[j] > 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ++ans;
    }
  }

  cout << ans << "\n";

  return 0;
}
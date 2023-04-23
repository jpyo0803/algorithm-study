// Milking Order (Bronze)
// http://www.usaco.org/index.php?page=viewproblem2&cpid=832

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;

  vector<int> pos(N + 1, -1);
  vector<int> hier(M);
  vector<int> exist_cnt(N + 1, 0);

  bool one_in_hier = false;
  for (int i = 0; i < M; ++i) {
    cin >> hier[i];
    if (hier[i] == 1) {
      one_in_hier = true;
    }
    exist_cnt[hier[i]]++;
  }

  vector<pair<int, int>> cow2pos(K);
  for (int i = 0; i < K; ++i) {
    cin >> cow2pos[i].first >> cow2pos[i].second;
    pos[cow2pos[i].second] = cow2pos[i].first;
    if (cow2pos[i].first == 1) {
      cout << cow2pos[i].second << "\n";
      return 0;
    }
    exist_cnt[cow2pos[i].first]++;
  }

  sort(cow2pos.begin(), cow2pos.end(),
       [](const pair<int, int>& x, const pair<int, int>& y) {
         return x.second < y.second;
       });

  if (one_in_hier == true) {
    int i = 0;
    int k = 1;
    while (i < hier.size()) {
      if (exist_cnt[hier[i]] == 2) {
        while (pos[k] != hier[i]) {
          k++;
        }
        k++;
        i++;
      } else {
        while (pos[k] != -1) {
          k++;
        }
        pos[k++] = hier[i++];
      }
    }
  } else {
    int i = hier.size() - 1;
    int k = N;
    while (i >= 0) {
      if (exist_cnt[hier[i]] == 2) {
        while (pos[k] != hier[i]) {
          k--;
        }
        k--;
        i--;
      } else {
        while (pos[k] != -1) {
          k--;
        }
        pos[k--] = hier[i--];
      }
    }

    for (int i = 1; i <= N; ++i) {
      if (pos[i] == -1) {
        pos[i] = 1;
        break;
      }
    }
  }

  for (int i = 1; i <= N; ++i) {
    if (pos[i] == 1) {
      cout << i << "\n";
    }
  }

  return 0;
}
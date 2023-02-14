// Cowntact Tracing
// http://www.usaco.org/index.php?page=viewproblem2&cpid=1037

#include <bits/stdc++.h>

using namespace std;

struct Record {
  int t, x, y;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N, T;
  cin >> N >> T;

  string s;
  cin >> s;

  vector<bool> result(N);
  for (int i = 0; i < s.length(); ++i) {
    result[i] = (s[i] == '1');
  }

  vector<Record> r(T);
  for (int i = 0; i < T; ++i) {
    cin >> r[i].t >> r[i].x >> r[i].y;
    r[i].x--;
    r[i].y--;
  }

  // sort chronically
  sort(r.begin(), r.end(),
       [](const Record& a, const Record& b) { return a.t < b.t; });

  int num_cand = 0, min_k = 1e9, max_k = 0;
  for (int i = 0; i < N; ++i) {  // assume i-th cow is patient 0

    bool ok = false;
    for (int j = 0; j <= 260;
         ++j) {  // assume K, use value larger than 250, to see its infiniteness
      vector<bool> simul(N, false);
      simul[i] = true;

      vector<int> k_try(N, j);

      for (int k = 0; k < T; ++k) {  // iterate over individual records
        bool after_x = false, after_y = false;
        if (simul[r[k].x] && k_try[r[k].x] > 0) {
          after_y = true;
          k_try[r[k].x]--;
        }
        if (simul[r[k].y] && k_try[r[k].y] > 0) {
          after_x = true;
          k_try[r[k].y]--;
        }
        simul[r[k].x] = simul[r[k].x] | after_x;
        simul[r[k].y] = simul[r[k].y] | after_y;
      }

      if (result == simul) {
        ok = true;
        min_k = min(min_k, j);
        max_k = max(max_k, j);
      }
    }
    if (ok) num_cand++;
  }

  cout << num_cand << " " << min_k << " ";
  if (max_k == 260) {
    cout << "Infinity\n";
  } else {
    cout << max_k << "\n";
  }

  return 0;
}
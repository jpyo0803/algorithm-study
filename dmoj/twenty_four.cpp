// Twenty-four  
// https://dmoj.ca/problem/ccc08s4

#include <bits/stdc++.h>

using namespace std;

int n;

int Solve(vector<int> rems) {
  if (rems.size() == 1) {
    return rems[0] > 24 ? 0 : rems[0];
  }
  
  int ret = 0;
  for (int i = 0; i < (int)rems.size() - 1; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (j == 0) { // +
        int new_val = rems[i] + rems[i + 1];
        vector<int> next_rems;
        for (int k = 0; k < rems.size(); ++k) {
          if (k == i) next_rems.push_back(new_val);
          else if (k == i + 1) continue;
          else next_rems.push_back(rems[k]);
        }
        ret = max(ret, Solve(next_rems));
      } else if (j == 1) {
        int new_val = rems[i] - rems[i + 1];
        vector<int> next_rems;
        for (int k = 0; k < rems.size(); ++k) {
          if (k == i) next_rems.push_back(new_val);
          else if (k == i + 1) continue;
          else next_rems.push_back(rems[k]);
        }
        ret = max(ret, Solve(next_rems));
      } else if (j == 2) {
        int new_val = rems[i] * rems[i + 1];
        vector<int> next_rems;
        for (int k = 0; k < rems.size(); ++k) {
          if (k == i) next_rems.push_back(new_val);
          else if (k == i + 1) continue;
          else next_rems.push_back(rems[k]);
        }
        ret = max(ret, Solve(next_rems));
      } else {
        if (rems[i + 1] != 0 && (rems[i] % rems[i + 1] == 0)) {
          int new_val = rems[i] / rems[i + 1];
          vector<int> next_rems;
          for (int k = 0; k < rems.size(); ++k) {
            if (k == i) next_rems.push_back(new_val);
            else if (k == i + 1) continue;
            else next_rems.push_back(rems[k]);
          }
          ret = max(ret, Solve(next_rems));
        }
      }
    }
  }

  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    int ans = 0;
    vector<int> cc;
    for (int j = 0; j < 4; ++j) {
      int x;
      cin >> x;
      cc.push_back(x);
    }

    sort(cc.begin(), cc.end());

    do {
      ans = max(ans, Solve(cc));
    } while (next_permutation(cc.begin(), cc.end()));
    cout << ans << "\n";
  }

  return 0;
}
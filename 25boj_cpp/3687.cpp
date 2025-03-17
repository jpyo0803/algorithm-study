// 성냥개비
// https://www.acmicpc.net/problem/3687

#include <bits/stdc++.h>

using namespace std;

int t, n;

int sticks[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;

  while (t--) {
    cin >> n;

    vector<int> min_ans, max_ans;

    int r;

    for (int i = 0; i < n / sticks[8]; ++i) min_ans.push_back(8);

    r = n % sticks[8];
    if (r >= 1) {
      int i;
      
      if (r == 1) {
        min_ans.pop_back();
        min_ans.push_back(0);
        min_ans.push_back(1);
      } else if (r == 2) {
        min_ans.push_back(1);
      } else if (r == 3) {
        min_ans.push_back(7);
      } else if (r == 4) {
        min_ans.push_back(4);
      } else if (r == 5) {
        min_ans.push_back(2);
      } else if (r == 6) {
        min_ans.push_back(6);
      }

      bool first;
      if (r == 1) {
        i = min_ans.size() - 2;
        first = false;
      } else {
        i = min_ans.size() - 1;
        first = true;
      }

      r = sticks[min_ans[i]];
      while (i > 0) {
        if (r == 1) {
          if (first) {
            min_ans[i] = 1;
            min_ans[i - 1] = 0;
            first = false;
          } else {
            min_ans[i] = 0;
            min_ans[i - 1] = 1;
          }
        } else if (r == 2) {
          if (first) {
            first = false;
          } else {
            min_ans[i] = 0;
            min_ans[i - 1] = 7;
          }
        } else if (r == 3) {
          if (first) {
            min_ans[i] = 2;
            min_ans[i - 1] = 2;
            first = false;
          } else {
            min_ans[i] = 0;
            min_ans[i - 1] = 4;
          }
        } else if (r == 4) {
          if (first) {
            min_ans[i] = 2;
            min_ans[i - 1] = 0;
            first = false;
          } else {
            min_ans[i] = 0;
            min_ans[i - 1] = 2;
          }
        } else if (r == 5) {
          if (first) {
            first = false;
          } else {
            min_ans[i] = 0;
            min_ans[i - 1] = 0;
          }
        } else if (r == 6) {
          break;
        }
        --i;
        r = sticks[min_ans[i]];
      }
    }

    for (int i = min_ans.size() - 1; i >= 0; --i) cout << min_ans[i];
    cout << " ";

    for (int i = 0; i < n / 2; ++i) max_ans.push_back(1);
    r = n % sticks[1];
    if (r == 1) {
      max_ans.pop_back();
      max_ans.push_back(7);
    }

    for (int i = max_ans.size() - 1; i >= 0; --i) cout << max_ans[i];
    cout << "\n";
  }

  return 0;
}
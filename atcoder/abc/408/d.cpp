// D - Flip to Gather (ABC)
// https://atcoder.jp/contests/abc408/tasks/abc408_d

#include <bits/stdc++.h>

using namespace std;

int t;
int c[200005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n;
    cin >> s;

    /*
      [l, r)
      Make s[i] to 1, l <= i < r
      Otherwise, make s[i] to 0

      using prefix sum
      the number of 1's or 0's in [l, r) can be found O(1)

      Let's say array A to store prefix sum of 0's
      and array B to store 1's

      Then, cost model C is
      Cost(l, r - 1) = B[n] - (B[r - 1] - B[l - 1]) + A[r - 1] - A[l - 1]
                  = B[n] + (A[r - 1] - B[r - 1]) - (A[l - 1] - B[l - 1])
      Define C[i] = A[i] - B[i]
      Cost(l, r - 1) = B[n] + C[r - 1] - C[l - 1]
                     = total # of 1's + (C[r - 1] - C[l - 1])

      To minimize cost, we want to find min of C[r - 1] - C[l - 1],
      This can be done in O(N), by replacing C[i] - max(C[< i])
    */

    c[0] = 0;
    for (int i = 0; i < n; ++i) {  // 1-indexed
      c[i + 1] = c[i] + (s[i] == '0' ? 1 : -1);
    }

    int sum1 = 0;
    for (auto ch : s) {
      if (ch == '1') sum1++;
    }

    int min_c = 0;
    int max_c = 0; // c[0] = 0
    for (int i = 1; i <= n; ++i) {
      min_c = min(min_c, c[i] - max_c);
      max_c = max(max_c, c[i]);
    }
    cout << sum1 + min_c << "\n";
  }

  return 0;
}
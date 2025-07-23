// F - Balanced Rectangles (ABC)
// https://atcoder.jp/contests/abc410/tasks/abc410_f

#include <bits/stdc++.h>

using namespace std;

int t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int h, w;
    cin >> h >> w;
    bool flipped = false;
    if (h > w) {
      flipped = true;
    }
    vector<vector<char>> arr(flipped ? w : h, vector<char>(flipped ? h : w));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> (flipped ? arr[j][i] : arr[i][j]);
      }
    }
    if (flipped) swap(h, w);

    vector<vector<long long>> ps(h, vector<long long>(w, 0));
    for (int j = 0; j < w; ++j) {
      long long sum = 0;
      for (int i = 0; i < h; ++i) {
        if (arr[i][j] == '#')
          sum++;
        else
          sum--;
        ps[i][j] = sum;
      }
    }

    long long ans = 0;

    vector<long long> cnt(h * w + 5, 0);
    vector<long long> ncnt(h * w + 5, 0);
    vector<long long> rec(w + 5);
    for (int u = 0; u < h; ++u) {
      for (int d = u; d < h; ++d) {
        cnt[0] = 1;
        long long sum = 0;
        for (int i = 0; i < w; ++i) {
          sum += ps[d][i] - (u - 1 >= 0 ? ps[u - 1][i] : 0);
          long long c = sum >= 0 ? cnt[sum] : ncnt[-sum];
          ans += c;
          if (sum >= 0) cnt[sum]++;
          else ncnt[-sum]++;
          rec[i] = sum;
        }
        for (int i = 0; i < w; ++i) {
          if (rec[i] >= 0) cnt[rec[i]]--;
          else ncnt[-rec[i]]--;
        }
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
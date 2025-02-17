// 문자열 게임 2
// https://www.acmicpc.net/problem/20437

#include <bits/stdc++.h>

using namespace std;

int t, k;
string w;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    cin >> w >> k;

    int len = w.length();

    vector<queue<int>> vq(256);

    int mmin = 1e9;
    int mmax = -1;
    for (int i = 0; i < len; ++i) {
      char ch = w[i];
      vq[ch].push(i);

      if (vq[ch].size() >= k) {
        if (vq[ch].size() > k) vq[ch].pop();
        
        int seq_len = i - vq[ch].front() + 1;
        mmin = min(mmin, seq_len);
        mmax = max(mmax, seq_len);
      }
    }
    if (mmax == -1) cout << "-1\n";
    else cout << mmin << " " << mmax << "\n";
  }

  return 0;
}
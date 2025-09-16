// 카탄의 개척자 
// https://www.acmicpc.net/problem/3678

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int f[10005];

int Solve(int n) { // 0-index
  f[0] = 1;
  int dc = 0; // div_cnt

  int i = 1;
  int L = 1;
  int s = 1, e = 6;
  
  int cnt[6]{};
  cnt[1] = 1;

  while (i <= n) {
    bool used[6]{};
    used[f[i - 1]] = true; 
    if (i % L == 0) {
      dc++;
      used[f[i - dc]] = true;
    } else {
      used[f[i - dc]] = true;
      if (i != s) used[f[i - dc - 1]] = true;
    }

    if (i == e) {
      used[f[s]] = true;
    }


    int val;
    int mi = 1e9;
    for (int j = 1; j <= 5; ++j) {
      if (used[j]) continue;
      if (cnt[j] < mi) {
        mi = cnt[j];
        val = j;
      }
    }
    f[i] = val;
    cnt[val]++;

    i++;
    if (i > e) {
      L++;
      s = e + 1;
      e = s + L * 6 - 1; 
    }
  }

  return f[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int c;
  cin >> c;
  while (c--) {
    int n;
    cin >> n;
    cout << Solve(n - 1) << "\n";
  }

  return 0;
}
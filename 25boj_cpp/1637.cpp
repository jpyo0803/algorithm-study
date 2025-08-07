// 날카로운 눈
// https://www.acmicpc.net/problem/1637

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;

  vector<tuple<long long, long long, long long>> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> get<0>(arr[i]) >> get<1>(arr[i]) >> get<2>(arr[i]);
  }

  long long l = 1LL, r = 2147483647LL;

  long long ans = -1, ans_cnt;
  while (l <= r) {
    long long mid = (l + r) / 2;

    long long cnt = 0;
    // count the number of values in [l, mid]
    for (int i = 0; i < n; ++i) {
      long long a = get<0>(arr[i]), c = get<1>(arr[i]), b = get<2>(arr[i]);
      long long low_k, high_k;
      
      long long lb = max(a, l), ub = min(c, mid);
      if (lb > ub) continue;

      long long q = (lb - a) / b;
      long long r = (lb - a) % b;
      low_k = r > 0 ? q + 1 : q;
      
      q = (ub - a) / b;
      high_k = q;

      cnt += high_k - low_k + 1;
    }

    if (l == r) {
      if (cnt % 2 == 1) {
        ans = mid;
        ans_cnt = cnt;
      }
      break;
    }

    if (cnt % 2 == 1) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }

  if (ans == -1) cout << "NOTHING\n";
  else cout << ans << " " << ans_cnt << "\n";

  return 0;
}
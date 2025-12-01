// G. Grouped Carriages
// https://codeforces.com/contest/1866/problem/G

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<tuple<int, int, int>> lr(n);
  for (int i = 0; i < n; ++i) {
    int d;
    cin >> d;
    lr[i] = {i - d, i + d, a[i]};
  }
  sort(lr.begin(), lr.end());

  vector<int> cnt(n);

  int lo = 0, hi = 1e9;
  while (lo < hi) {
    int z = lo + (hi - lo) / 2;

    for (int i = 0; i < n; ++i) cnt[i] = 0;

    priority_queue<tuple<int, int, int>> pq; // -R, L, rem
    
    bool ok = true;
    int j = 0;
    for (int i = 0; i < n; ++i) {
      while (j < n && get<0>(lr[j]) <= i) {
        if (get<2>(lr[j]) > 0) {
          pq.emplace(-get<1>(lr[j]), get<0>(lr[j]), get<2>(lr[j]));
        }
        j++;
      }

      while (pq.size() && cnt[i] < z) {
        int l, r, rem;
        tie(r, l, rem) = pq.top();
        pq.pop();
        r = -r;

        if (r < i) {
          ok = false;
          break;
        }

        int amt = min(z - cnt[i], rem);
        cnt[i] += amt;
        rem -= amt;
        if (rem > 0) {
          pq.emplace(-r, l, rem);
        }
      }
    }

    if (pq.size()) ok = false;

    if (ok) {
      hi = z;
    } else {
      lo = z + 1;
    }
  }

  cout << hi << "\n";

  return 0;
}
// High Card Low Card (Gold)
// https://www.acmicpc.net/problem/11963

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  vector<bool> used(2 * n + 1);
  vector<int> bv(n);
  for (int i = 0; i < n; ++i) {
    cin >> bv[i];
    used[bv[i]] = true;
  }

  set<int> es;
  for (int i = 1; i <= 2 * n; ++i) {
    if (used[i] == false) {
      es.insert(i);
    }
  }

  vector<int> av(n); // assigned
  for (int i = 0; i < n / 2; ++i) {
    auto it = es.lower_bound(bv[i]);
    if (it == es.end()) av[i] = -1;
    else {
      av[i] = *it;
      es.erase(it);
    }
  }
  for (int i = 0; i < n / 2; ++i) {
    if (av[i] == -1) continue;
    auto last = es.end();
    last--;

    if (av[i] < *last) {
      int tmp = av[i];
      av[i] = *last;
      es.erase(last);
      es.insert(tmp); // swap
    }
  }

  int ans = 0;

  for (int i = 0; i < n / 2; ++i) {
    if (av[i] != -1) {
      ans++;
      continue;
    }
    auto last = es.end();
    last--;
    av[i] = *last;
    es.erase(last);
  }

  for (int i = n / 2; i < n; ++i) {
    auto it = es.lower_bound(bv[i]);
    if (it != es.begin()) {
      --it;
      ans++;
      es.erase(it);
    }
  }

  cout << ans << "\n";

  return 0;
}
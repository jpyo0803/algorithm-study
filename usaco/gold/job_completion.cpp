// Job Completion (Gold)
// https://usaco.org/index.php?page=viewproblem2&cpid=1451

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    vector<pair<ll, ll>> vv;
    for (int i = 0; i < n; ++i) {
      ll s, t;
      cin >> s >> t;
      vv.emplace_back(s, t);
    }
    
    sort(vv.begin(), vv.end(), [](pair<ll, ll> a, pair<ll, ll> b) {
      return a.first + a.second < b.first + b.second; 
    });

    priority_queue<ll> pq;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += vv[i].second;
      pq.push(vv[i].second);
      if (sum > vv[i].first + vv[i].second) {
        sum -= pq.top();
        pq.pop();
      }
    }

    cout << pq.size() << "\n";
  }

  return 0;
}
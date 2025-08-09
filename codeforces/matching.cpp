// G. Matching
// https://codeforces.com/gym/104417/problem/G?mobile=true

#include <bits/stdc++.h>

using namespace std;

int t;
int arr[100005];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> arr[i];

    map<int, vector<int>> mm;
    for (int i = 1; i <= n; ++i) {
      mm[i - arr[i]].push_back(i);
    }

    long long ans = 0;
    for (auto& e : mm) {
      auto& v = e.second;
      sort(v.begin(), v.end(), [](int a, int b) {
        return arr[a] > arr[b];
      });
      for (int i = 0; i + 1 < v.size(); i += 2) {
        int sum = arr[v[i]] + arr[v[i + 1]];
        if (sum > 0) ans += sum;
      }
    }
    cout << ans << "\n";
  }

  return 0;
}
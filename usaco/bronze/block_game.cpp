// Block Game (Bronze)
// https://www.acmicpc.net/problem/14174

#include <bits/stdc++.h>

using namespace std;

int n;
int ans[26];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;

    int cnt_a[26]{};
    int cnt_b[26]{};
    for (auto ch : a) cnt_a[ch - 'a']++;
    for (auto ch : b) cnt_b[ch - 'a']++;

    for (int i = 0; i < 26; ++i) {
      ans[i] += max(cnt_a[i], cnt_b[i]);
    }
  }

  for (int i = 0; i < 26; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}
// 6174
// https://www.acmicpc.net/problem/9047

#include <bits/stdc++.h>

using namespace std;

int t;
pair<int, int> Arr2SmallestLargest(array<int, 4> arr) {
  sort(arr.begin(), arr.end());
  int s = 0, l = 0;
  for (int i = 0; i < 4; ++i) {
    s = s * 10 + arr[i];
    l = l * 10 + arr[4 - i - 1];
  }
  return {s, l};
}

array<int, 4> Num2Arr(int x) {
  array<int, 4> ret;
  for (int i = 0; i < 4; ++i) {
    ret[i] = x % 10;
    x /= 10;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> t;
  while (t--) {
    int x;
    cin >> x;

    int ans = 0;
    while (x != 6174) {
      array<int, 4> arr = Num2Arr(x);
      int s, l;
      tie(s, l) = Arr2SmallestLargest(arr);
      x = l - s;
      ans++;
    }
    cout << ans << "\n";
  }

  return 0;
}
// 일곱 난쟁이
// https://www.acmicpc.net/problem/2309

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int arr[9];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n = 0;
  for (int i = 0; i < 9; ++i) {
    cin >> arr[i];
    n += arr[i];
  }
  sort(arr, arr + 9);

  for (int i = 0; i < 8; ++i) {
    for (int j = i + 1; j < 9; ++j) {
      if (n - arr[i] - arr[j] == 100) {
        for (int k = 0; k < 9; ++k) {
          if (k == i || k == j) continue;
          cout << arr[k] << "\n";
        }
        return 0;
      }
    }
  }

  return 0;
}
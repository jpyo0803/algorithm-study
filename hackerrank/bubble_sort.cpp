// Bubble Sort
// https://www.hackerrank.com/challenges/ctci-bubble-sort/problem

#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) cin >> arr[i];

  int num_swaps = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        num_swaps++;
      }
    }
  }

  cout << "Array is sorted in " << num_swaps << " swaps." << "\n";
  cout << "First Element: " << arr.front() << "\n";
  cout << "Last Element: " << arr.back() << "\n";

  return 0;
}
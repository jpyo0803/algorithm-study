// Bubble Sort (HackerRank)
// https://www.hackerrank.com/challenges/ctci-bubble-sort/problem

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int N;
  cin >> N;

  vector<int> arr(N);
  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
  }

  int num_swaps = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        num_swaps++;
      }
    }
  }

  cout << "Array is sorted in " << num_swaps << " swaps.\n";
  cout << "First Element: " << arr[0] << "\n";
  cout << "Last Element: " << arr[N - 1] << "\n";

  return 0;
}
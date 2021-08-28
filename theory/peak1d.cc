/*
  Peak Finder 1-D.
  This algorithm finds a peak from 1-D array
  It uses divide and conquer algorithm
  Time complexity is log2(n)
*/

#include <iostream>
#include <random_number_generator.hpp>

using namespace std;

int N = 2048;
int* arr;

int time_complexity = 0;
int find_peak1d(int arr[], int left, int right) {
  time_complexity++;
  int mid = (left + right) / 2;
  if (mid - 1 >= 0 && arr[mid - 1] > arr[mid]) {
    return find_peak1d(arr, left, mid - 1);
  } else if (mid + 1 < N && arr[mid + 1] > arr[mid]) {
    return find_peak1d(arr, mid + 1, right);
  }
  return arr[mid];
}

void print_arr(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main() {
  arr = new int[N];
  int peak_pos = get_random_number(0, N - 1);
  int peak_val = get_random_number(0, N * 100);
  arr[peak_pos] = peak_val;

  for (int i = peak_pos + 1; i < N; i++) {
    int next_val = arr[i - 1] - get_random_number(1, 5);
    arr[i] = next_val < 0 ? 0 : next_val;
  }
  for (int i = peak_pos - 1; i >= 0; i--) {
    int next_val = arr[i + 1] - get_random_number(1, 5);
    arr[i] = next_val < 0 ? 0 : next_val;
  }

  cout << endl;

  int res = find_peak1d(arr, 0, N - 1);
  cout << "found val = " << res << "\nreal value = " << peak_val << endl;
  cout << "sample size = " << N << " / Time complexity = " << time_complexity
       << endl;
  return 0;
}
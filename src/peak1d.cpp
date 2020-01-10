/* 
  Peak Finder 1-D.
  This algorithm finds a peak from 1-D array 
  It uses divide and conquer algorithm
  Time complexity is log2(n)
*/

#include <iostream>

using namespace std;

int n = 10;
int arr[10] = {1, 2, 3, 4, 5, 8, 23, 88, 99, 100};

int solve(int left, int right) {
  int mid = (left + right) / 2;
  if (arr[mid-1] >= arr[mid]) {
    return solve(left, mid-1);
  } else if (arr[mid+1] >= arr[mid]) {
    return solve(mid+1, right);
  } else {
    return mid;
  }
}

int main() {
  int res = solve(0, n-1);
  cout << "answer is " << arr[res] << " at " << res << "\n";
  return 0;
}
/* 
  Peak Finder 2-D.
  This algorithm finds a peak from 2-D array 
  It uses divide and conquer algorithm
  Time complexity is n*log2(m)
*/
#include <iostream>

using namespace std;

int n = 4;
int arr[4][4] = 
{
  {4, 3, 2, 1},
  {5, 2, 1, 99},
  {6, 2, 2, 88},
  {7, 8, 9, 10},
};

int ans_i = 0;
int ans_j = 0;

void solve(int left, int right) {
  int j = (left + right) / 2;
  int glob_max = 0;
  int i = 0;
  for (int k = 0; k < n; k++) { // Theta(n)
    if (arr[k][j] > glob_max) {
      glob_max = arr[k][j];
      i = k;
    }
  }

  if (j - 1 >= 0 && arr[i][j-1] > arr[i][j]) {
    solve(left, j-1);
  } else if (j + 1 < n && arr[i][j+1] > arr[i][j]) {
    solve(j+1, right);
  } else {
    ans_i = i;
    ans_j = j;
    return;
  }
}
int main() {

  solve(0, n-1);
  cout << "answer is " << arr[ans_i][ans_j] << " at (" << ans_i << ", " << ans_j << ")\n";
  
  return 0;
}
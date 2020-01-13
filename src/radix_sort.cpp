/*
  Implementation of Radix sort
  O((n+b)*d) = O((n+b)*log_b(k)), where d = max #digit, n = input size, b = base, k = max possible value
  
*/
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int* nums;
int limit = 100000000;
int n = 10000;
int k = 0;
int digit;
// base = 10

int number_generator() {
  return rand() % limit;
}

void print_arr(int arr[]) {
  for (int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int nth_digit(int val, int n) {
  int i = 0;
  int ret;
  while (i < n) {
    ret = val % 10;
    val /= 10;
    i++;
  }
  return ret;
}
void radix_sort() {
  for (int i = 1; i <= digit; i++) {
    queue<int> ques[10]; // for digit 0 ~ 9
    for (int j = 0; j < n; j++) {
      int curr_digit = nth_digit(nums[j], i);
      ques[curr_digit].push(nums[j]);
    }
    int idx = 0;
    for (int j = 0; j < 10; j++) {
      while (!ques[j].empty()) {
        nums[idx++] = ques[j].front();
        ques[j].pop();
      }
    }
  }
}
int main() {
  srand((unsigned int)time(NULL));

  nums = new int[n];
  for (int i = 0; i < n; i++) {
    nums[i] = number_generator();
    if (nums[i] > k) k = nums[i];
  }
  digit = ceil(log10(k));

  //cout << "unsorted : ";
  //print_arr(nums);

  radix_sort();

  //cout << "\nsorted : ";
  //print_arr(nums);

  bool pass = true;

  for (int i = 0; i < n - 1; i++) {
    if (nums[i] > nums[i+1]) {
      pass = false;
      break;
    }
  }

  if (pass) cout << "pass\n";
  else cout << "no pass\n";

  delete[] nums;
  return 0;
}
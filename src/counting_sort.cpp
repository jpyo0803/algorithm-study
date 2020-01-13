/*
  Implementation of Counting sort,
  O(n+k), where n is # inputs and k is the max value among input
  so when k is too big compared to the size of n like k = n^2, 
  it becomes worse than the comparison based sorting algorithms
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n = 20;
vector<int> arr;

int main() {
  srand((unsigned int)time(NULL));

  int k = 0;
  for (int i = 0; i < n; i++) {
    int num = rand() % 100;
    if (k < num) k = num;
    arr.push_back(num);
  }

  int* count = new int[k+1];
  memset(count, 0x00, sizeof(int)*(k+1));

  for (int i = 0; i < arr.size(); i++) {
    count[arr[i]] += 1;
  }

  for (int i = 0; i <= k; i++) {
    while (count[i] != 0) {
      cout << i << " ";
      count[i]--;
    }
  }
  cout << endl;

  delete[] count;
  return 0;
}
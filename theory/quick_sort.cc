//
// Quick Sort(very basic form), Randomized Partition
// O(nlogn), but O(n^2) if order is reversed
//

#include <iostream>
#include <random_number_generator.hpp>
#include <vector>

using namespace std;
const int MAX{30};
const int N{100};

void swap(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int partition(vector<int>& arr, int l, int r) {
  int key = arr[r];
  int i = l;
  for (int j = l; j < r; j++) {
    if (arr[j] < key) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[r]);
  return i;
}

int randomized_partition(vector<int>& arr, int l, int r) {
  int rn = get_random_number(l, r);
  swap(arr[rn], arr[r]);
  return partition(arr, l, r);
}

void quick_sort(vector<int>& arr, int l, int r) {
  if (l < r) {
    int pivot = randomized_partition(arr, l, r);
    quick_sort(arr, l, pivot - 1);
    quick_sort(arr, pivot + 1, r);
  }
}

int main() {
  vector<int> arr;
  for (int i = 0; i < MAX; i++) {
    arr.push_back(get_random_number(0, N) - (N / 2));
  }

  cout << "unsorted: " << endl;
  for (auto e : arr) {
    cout << e << " ";
  }
  cout << endl << endl;

  quick_sort(arr, 0, arr.size() - 1);

  cout << "sorted: " << endl;
  for (auto e : arr) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}

/*
  Merge sort implementation
  O(nlogn)
  Merge sort's advantage is that it almost always keeps nlogn (ie, quick sort sometimes gets O(n^2) worst case)
  But bad side is that it requires extra space for merge operation 
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void arr_print(const vector<int>& v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int n = 1000;
vector<int> arr;

void merge(int left, int right) {
  int mid = (left + right) / 2;
  int L1 = mid - left + 1;
  int L2 = right - mid;
  queue<int> v1;
  queue<int> v2;

  for (int i = 0; i < L1; i++) {
    v1.push(arr[left + i]);
  }
  for (int i = 0; i < L2; i++) {
    v2.push(arr[mid + 1 + i]);
  }

  int kp = left;

  while (!v1.empty() && !v2.empty()) {
    if (v1.front() < v2.front()) {
      arr[kp] = v1.front();
      v1.pop();
    } else {
      arr[kp] = v2.front();
      v2.pop();
    }
    kp++;
  }

  while (!v1.empty()) {
    arr[kp] = v1.front();
    v1.pop();
    kp++;
  }
  while (!v2.empty()) {
    arr[kp] = v2.front();
    v2.pop();
    kp++;
  }
}
void mergeSort(int left, int right) {
  if (left == right) {  // if same
    // nop
  } else {
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, right);
  }
}

int main() {
  srand((unsigned int)time(NULL));

  for (int i = 0; i < n; i++) {
    arr.push_back((rand() % 10000) - 5000);
  }

  cout << "before sorted: \n";
  arr_print(arr);
  mergeSort(0, n - 1);
  cout << "\nafter sorted: \n";
  arr_print(arr);

  vector<int> tmp;
  for (int i = 0; i < arr.size(); i++) {
    tmp.push_back(arr[i]);
  }

  sort(arr.begin(), arr.end());

  bool same = true;
  for (int i = 0; i < arr.size(); i++) {
    if (tmp[i] != arr[i]) {
      same = false;
      break;
    }
  }
  if (same) cout << "match!\n";
  else cout << "Not match!\n";


  return 0;
}

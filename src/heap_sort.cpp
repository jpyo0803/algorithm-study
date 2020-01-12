/*
  Heap sort
  O(nlogn)
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void arr_print(const vector<int>& v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int heap_size = 1000;
vector<int> arr;

void build_max_heap();
void max_heapify(int node);
int extract_max();

int main() {
  srand((unsigned int)time(NULL));

  for (int i = 0; i < heap_size; i++) {
    arr.push_back((rand() % heap_size) - heap_size/2);
  }

  cout << "before sorted: \n";
  arr_print(arr);

  build_max_heap();

  while (heap_size > 0) {
    extract_max();
  }
  cout << "\nafter sorted: \n";
  arr_print(arr);

  bool pass = true;
  for (int i = 0; i < arr.size()-1; i++) {
    if (arr[i] > arr[i+1]) pass = false;
  }

  if (pass) cout << "passed\n";
  else cout << "Failed to pass\n";

  return 0;
}

int extract_max() {
  swap(&arr[0], &arr[heap_size-1]);
  heap_size--;
  max_heapify(0);
  return arr[heap_size];
}

void build_max_heap() {
  for (int i = heap_size / 2 + 1; i >= 0; i--) {
    max_heapify(i);
  }
}

void max_heapify(int node) {
  int lcp, rcp;
  lcp = rcp = -1;

  int offset = node * 2 + 1;
  if (offset < heap_size) {
    lcp = offset;
    if (offset + 1 < heap_size) {
      rcp = offset + 1;
    }
  }

  int lcv, rcv;
  if (lcp != -1) lcv = arr[lcp];
  if (rcp != -1) rcv = arr[rcp];

  if (lcp != -1 || rcp != -1) {
    int ncp = -1;
    int bigger_cp;
    if (lcp != -1 && rcp != -1) {
      bigger_cp = (lcv > rcv) ? lcp : rcp;
    } else if (lcp != -1) {
      bigger_cp = lcp;
    } else {
      bigger_cp = rcp;
    }

    if (arr[bigger_cp] > arr[node]) {
      swap(&arr[bigger_cp], &arr[node]);
      ncp = bigger_cp;
    } 

    if (ncp != -1) {
      max_heapify(ncp);
    }
  }
}
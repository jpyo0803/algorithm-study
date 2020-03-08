/*
  minheap, maxheap, 
  O(nlogn)
*/

#include <random_number_generator.hpp>
#include <iostream>
#include <heap_pq.hpp>
#include <vector>

#define MAX_NUM 20

using namespace std;

bool already_been[MAX_NUM];

int main() {

  cout << "Max heap example : \n\n";
  Max_Heap<int, int> MaxHeap;
  for (int i = 0; i < 10; i++) {
     int rn = get_random_number(1, MAX_NUM - 1);
     while (already_been[rn]) {
       rn = get_random_number(1, MAX_NUM - 1);
     }
     already_been[rn] = true;

    Container<int, int>* tmp_ptr = new Container<int, int>(rn, rn);
    MaxHeap.insert(tmp_ptr);
  }

  while (!MaxHeap.is_empty()) {
    Container<int, int>* cont = MaxHeap.extract_max();
    if (cont != nullptr) {
      cout << cont->obj << endl;
      delete cont;
    }
  }

  for (int i = 0; i < MAX_NUM; i++) {
    already_been[i] = false;
  }
  cout << "\n\nMin heap example :\n\n";
  Min_Heap<int, int> MinHeap;
  for (int i = 0; i < 10; i++) {
     int rn = get_random_number(1, MAX_NUM - 1);
     while (already_been[rn]) {
       rn = get_random_number(1, MAX_NUM - 1);
     }
     already_been[rn] = true;

    Container<int, int>* tmp_ptr = new Container<int, int>(rn, rn);
    MinHeap.insert(tmp_ptr);
  }

  while (!MinHeap.is_empty()) {
    Container<int, int>* cont = MinHeap.extract_min();
    if (cont != nullptr) {
      cout << cont->obj << endl;
      delete cont;
    }
  }
  return 0;
}
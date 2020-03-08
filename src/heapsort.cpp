/*
  minheap, maxheap, 
  O(nlogn)
*/

#include <random_number_generator.hpp>
#include <iostream>
#include <heap_priority_queue.hpp>
#include <vector>

#define MAX_NUM 1000

using namespace std;

int main() {

  cout << "Max heap example : \n\n";

  Max_Heap<int, int> MaxHeap;
  for (int i = 0; i < 20; i++) {
    int rn = get_random_number(1, MAX_NUM - 1);
    MaxHeap.insert(rn, rn);
  }

  auto some_max = MaxHeap.get_max();
  MaxHeap.update_key(some_max, 777);
  while (!MaxHeap.is_empty()) {
    auto cont = MaxHeap.extract_max();
    cout << cont->key << endl;
  }


  cout << "\n\nMin heap example :\n\n";
  Min_Heap<int, int> MinHeap;
  for (int i = 0; i < 20; i++) {
    int rn = get_random_number(1, MAX_NUM - 1);
    MinHeap.insert(rn, rn);
  }

  auto some_min = MinHeap.get_min();
  MinHeap.update_key(some_min, 777);

  while (!MinHeap.is_empty()) {
    auto cont = MinHeap.extract_min();
    cout << cont->key << endl;
  }
  return 0;
}
/*
  minheap, maxheap,
  O(nlogn)
*/

#include <heap_priority_queue.hpp>
#include <iostream>
#include <random_number_generator.hpp>
#include <vector>

#define MAX_NUM 200

using namespace std;

int main() {
  cout << "Max heap example : \n\n";

  vector<Container<double>> arr;
  for (int i = 0; i < 50; i++) {
    int rn = get_random_number(0, MAX_NUM);
    arr.emplace_back(rn, rn);
  }

  Max_Heap<double> mh;
  mh.Build_Max_Heap(arr);
  mh.Heap_Increase_Key(30, 7777);
  mh.Max_Heap_Insert(8888, 0.5);

  int prev = -1;
  int now;
  bool pass{true};
  while (!mh.is_empty()) {
    auto container = mh.Heap_Extract_Max();
    cout << container.key << " ";
    if (prev == -1) {
      prev = container.key;
    } else {
      now = container.key;
      if (prev < now) {
        pass = false;
        break;
      }
    }
  }
  cout << endl;
  cout << "pass : " << pass << endl;

  return 0;
}
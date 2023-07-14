/*
  Bubble sort
  O(n^2)
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void arr_print(const vector<int> &v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int n = 10;
vector<int> arr;

void solve();

int main() {
  srand((unsigned int)time(NULL));

  for (int i = 0; i < n; i++) {
    arr.push_back((rand() % 50) - 25);
  }

  cout << "before sorted: \n";
  arr_print(arr);
  solve();
  cout << "\nafter sorted: \n";
  arr_print(arr);

  bool pass{true};
  for (int i = 0; i < arr.size() - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      pass = false;
      break;
    }
  }

  if (pass) {
    cout << "passed!" << endl;
  } else {
    cout << "failed!" << endl;
  }

  return 0;
}

void solve() {
  for (int i = 1; i < arr.size(); i++) {
    for (int j = arr.size() - 1; j >= i; j--) {
      if (arr[j - 1] > arr[j]) {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}
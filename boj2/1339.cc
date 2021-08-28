//
// Word Math
// Problem: https://www.acmicpc.net/problem/1339
//

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int N;
unordered_map<char, int> coeff_map;
vector<int> coeff_vec;

void swap(int& x, int& y) {
  int temp = x;
  x = y;
  y = temp;
}

int parition(vector<int>& arr, int l, int r) {
  int key = arr[r];
  int i = l;
  for (int j = l; j < r; j++) {
    if (arr[j] > key) {
      swap(arr[i], arr[j]);
      i++;
    }
  }
  swap(arr[i], arr[r]);
  return i;
}
void quicksort(vector<int>& arr, int l, int r) {
  if (l < r) {
    int pivot = parition(arr, l, r);
    quicksort(arr, l, pivot - 1);
    quicksort(arr, pivot + 1, r);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;

  string word;
  for (int i = 0; i < N; i++) {
    cin >> word;
    int mulplier = 1;
    for (int j = word.length() - 1; j >= 0; j--) {
      coeff_map[word[j]] += mulplier;
      mulplier *= 10;
    }
  }

  for (auto it : coeff_map) {
    coeff_vec.push_back(it.second);
  }
  quicksort(coeff_vec, 0, coeff_vec.size() - 1);

  int i = 9;
  int sum = 0;
  for (auto it : coeff_vec) {
    sum += (i * it);
    i--;
  }
  cout << sum;
  return 0;
}
/*
  Insersion sort
  O(n^2)
  key iterates thru the array from 1 to n-1, everytime it relocates the key into its right place
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
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
    srand((unsigned int) time(NULL));

    for (int i = 0; i < n; i++) {
        arr.push_back((rand() % 50) - 25);
    }

    cout << "before sorted: \n";
    arr_print(arr);
    solve();
    cout << "\nafter sorted: \n";
    arr_print(arr);

    return 0;
}

void solve() {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
}
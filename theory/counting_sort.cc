/*
  Implementation of Counting sort,
  O(n+k), where n is # inputs and k is the max value among input
  so when k is too big compared to the size of n like k = n^2, 
  it becomes worse than the comparison based sorting algorithms
*/

#include <iostream>
#include <vector>
#include <random_number_generator.hpp>

using namespace std;

const int N{50};
const int K{30};
int unsorted[N];
int sorted[N];

int temp[K];

int main() {
    cout << "Unsorted: ";
    for (int i = 0; i < N; i++) {
        unsorted[i] = get_random_number(0, K - 1);
        cout << unsorted[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; i++) {
        temp[unsorted[i]] += 1;
    }

    for (int i = 1; i < K; i++) {
        temp[i] += temp[i - 1];
    }

    for (int j = N - 1; j >= 0; j--) {
        sorted[temp[unsorted[j]]] = unsorted[j];
        temp[unsorted[j]] -= 1;
    }

    cout << "Sorted: ";
    for (int i = 0; i < N; i++) {
        cout << sorted[i] << " ";
    }
    cout << endl;

    return 0;
}
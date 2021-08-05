//
// K-th smallest number
// Problem: https://www.acmicpc.net/problem/11004
//

#include <iostream>
#include <algorithm>

using namespace std;
const int MAX_SIZE{5000000};
int N, K, e;
int nums[MAX_SIZE];


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    nth_element(nums, nums + K - 1, nums + N);
    cout << nums[K - 1];

    return 0;
}

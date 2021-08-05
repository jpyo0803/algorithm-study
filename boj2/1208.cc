//
// Subset sum 2
// Problem: https://www.acmicpc.net/problem/1208
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX{40};
int N, S, e;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> S;
    vector<int> arr1, arr2;
    arr1.push_back(0);
    arr2.push_back(0);

    for (int i = 0; i < N / 2; i++) {
        cin >> e;
        int sz = arr1.size();
        for (int j = 0; j < sz; j++) {
            arr1.push_back(arr1[j] + e);
        }
    }

    for (int i = 0; i < N - (N / 2); i++) {
        cin >> e;
        int sz = arr2.size();
        for (int j = 0; j < sz; j++) {
            arr2.push_back(arr2[j] + e);
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    uint64_t ans = 0;

    int i = 0;
    int j = arr2.size() - 1;
    bool done{false};
    while (!done) {
        int key_i{arr1[i]};
        int key_j{arr2[j]};

        if (S > key_i + key_j) {
            i++;
        } else if (S < key_i + key_j) {
            j--;
        } else {
            uint64_t i_count{0}, j_count{0};
            while (i < arr1.size() && key_i == arr1[i]) {
                i += 1;
                i_count += 1;
            }
            while (j >= 0 && key_j == arr2[j]) {
                j -= 1;
                j_count += 1;
            }
            ans += (i_count * j_count);
        }
        if (i >= arr1.size() || j < 0) done = true;
    }
    if (S == 0) ans -= 1;
    cout << ans;
    return 0;
}
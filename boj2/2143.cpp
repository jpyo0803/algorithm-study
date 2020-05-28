//
// Sum of two arrays
// Problem: https://www.acmicpc.net/problem/2143
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX{1000};
int T, N, M;
int A[MAX];
int B[MAX];

void calc_subarray_sum(vector<int>& vec, int arr[], int sz) {
    for (int i = 0; i < sz; i++) {
        int sum{0};
        for (int j = i; j < sz; j++) {
            sum += arr[j];
            vec.push_back(sum);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> sub_sumA, sub_sumB;
    cin >> T;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> B[i];

    calc_subarray_sum(sub_sumA, A, N);
    calc_subarray_sum(sub_sumB, B, M);

    sort(sub_sumA.begin(), sub_sumA.end());
    sort(sub_sumB.begin(), sub_sumB.end());

    int64_t ans{0};
    int i = 0, j = sub_sumB.size() - 1;

    while (i < sub_sumA.size() && j >= 0) {
        int sum{sub_sumA[i] + sub_sumB[j]};
        if (sum == T) {
            int64_t count1{1}, count2{1};
            while (i + 1 < sub_sumA.size() && sub_sumA[i + 1] == sub_sumA[i]) {
                count1 += 1;
                i += 1;
            }
            while (j - 1 >= 0 && sub_sumB[j - 1] == sub_sumB[j]) {
                count2 += 1;
                j -= 1;
            }
            ans += count1 * count2;
            i++; j--;
        } else if (sum < T) {
            i++;
        } else {
            j--;
        }
    }

    cout << ans;
    return 0;
}


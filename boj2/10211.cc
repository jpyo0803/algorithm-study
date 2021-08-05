//
// Maximum Subarray
// Problem: https://www.acmicpc.net/problem/10211
//

#include <iostream>

#define MODE 1 // 0 = Divide and conquer = O(nlgn), 1 = linear probing = O(n)

using namespace std;

const int MAX{1000};
const int NINF{-100000000};
int T, N;

#if (MODE == 0)
int nums[MAX];
int max_subarr_cross(int arr[], int l, int r) {
    int left_max{NINF}, right_max{NINF};

    int mid = (l + r) / 2;
    int sum{0};
    for (int i = mid; i >= l; i--) {
        sum += arr[i];
        if (left_max < sum) {
            left_max = sum;
        }
    }

    sum = 0;
    for (int i = mid + 1; i <= r; i++) {
        sum += arr[i];
        if (right_max < sum) {
            right_max = sum;
        }
    }
    return left_max + right_max;
}

int max_subarr(int arr[], int l, int r) {
    if (l == r) return arr[l];
    int mid = (l + r) / 2;
    return max(max(max_subarr(arr, l, mid),  max_subarr(arr, mid + 1, r)), max_subarr_cross(arr, l, r));
}
#else
int max_subarr(int n) {
    int max_sum = NINF;
    int sum = 0;
    int e;
    for (int i = 0; i < n; i++) {
        cin >> e;
        sum += e;
        max_sum = max(max_sum, sum);
        if (sum < 0) sum = 0;
    }
    return max_sum;
}
#endif
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int tc = 0; tc < T; tc++) {
        cin >> N;
#if (MODE == 0)
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        cout << max_subarr(nums, 0, N - 1) << endl;
#else
        cout << max_subarr(N) << endl;
#endif
    }
    return 0;
}
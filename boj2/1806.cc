//
// Consecutive Subset Sum
// Problem: https://www.acmicpc.net/problem/1806
//

#include <iostream>

using namespace std;
const int MAX{100000};
const int INF{100000000};
int N, S;
int nums[MAX];

int solve() {
    int i{0}, j{0};

    int running_sum = nums[0];
    int max_len = INF;
    do {
        if (running_sum < S) {
            running_sum += nums[++j];
        } else { // match
            if (j - i + 1 < max_len) {
                max_len = j - i + 1;
            }
            running_sum -= nums[i++];
        }
    } while (i < N && j < N);
    if (max_len == INF) return 0;
    return max_len;
}

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> S;

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    cout << solve();

    return 0;
}
//
// Put boxes
// Problem: https://www.acmicpc.net/problem/1965
//

#include <iostream>

#define MODE 1 // 0 = Memoization, 1 = Tabulation

using namespace std;

const int MAX_SIZE{1000};
int N;
int boxes[MAX_SIZE + 1];
int dp[MAX_SIZE + 1];

#if (MODE == 0)
bool filled[MAX_SIZE + 1];
int memo_method(int i) {
    if (i == 0) return 0;
    if (filled[i]) return dp[i];

    int prev_max = 0;
    for (int j = 1; j < i; j++) {
        if (boxes[j] < boxes[i]) {
            if (prev_max < dp[j]) {
                prev_max = dp[j];
            }
        }
    }
    dp[i] = prev_max + 1;
    filled[i] = true;
    return dp[i];
}
#else
int tabulate_method(int n) {
    dp[1] = 1;

    int ans = dp[1];
    for (int i = 2; i <= n; i++) {
        int prev_max = 0;
        for (int j = 1; j < i; j++) {
            if (boxes[j] < boxes[i]) {
                if (prev_max < dp[j]) {
                    prev_max = dp[j];
                }
            }
        }
        dp[i] = prev_max + 1;
        if (ans < dp[i]) {
            ans = dp[i];
        }
    }
    return ans;
}
#endif

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> boxes[i];
    }

#if (MODE == 0)
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int res = memo_method(i);
        if (ans < res) {
            ans = res;
        }
    }
    cout << ans;
#else
    cout << tabulate_method(N);
#endif

    return 0;
}



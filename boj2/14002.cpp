//
// Longest Increasing subsequence
// Problem: https://www.acmicpc.net/problem/14002
//

#include <iostream>

#define MODE 1 // 0 = memo, 1 = tabu

using namespace std;
const int MAX{1000};
int N;
int nums[MAX];
int dp[MAX];
int p[MAX];

#if (MODE == 0)
bool filled[MAX];
int memo_method(int i) {
    if (filled[i]) return dp[i];

    int local_max = 0;
    int max_ind = i;
    for (int j = i + 1; j < N; j++) {
        if (nums[i] < nums[j]) {
            int ret = memo_method(j);
            if (local_max < ret) {
                local_max = ret;
                max_ind = j;
            }
        }
    }
    dp[i] = local_max + 1;
    p[i] = max_ind;
    filled[i] = true;
    return dp[i];
}
#else
int tabulate_method(int n) {
    int ans_ind = 0;
    for (int i = n - 1; i >= 0; i--) {
        int local_max = 0;
        int max_ind = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] < nums[j]) {
                if (local_max < dp[j]) {
                    local_max = dp[j];
                    max_ind = j;
                }
            }
        }
        dp[i] = local_max + 1;
        p[i] = max_ind;
        if (dp[ans_ind] < dp[i]) {
            ans_ind = i;
        }
    }
    return ans_ind;
}
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) cin >> nums[i];

    int glob_max = 0;
    int ans_ind = 0;
#if (MODE == 0)
    for (int i = 0; i < N; i++) {
        int ret = memo_method(i);
        if (glob_max < ret) {
            glob_max = ret;
            ans_ind = i;
        }
    }
#else
    ans_ind = tabulate_method(N);
#endif

    cout << dp[ans_ind] << endl;
    while (true) {
        if (ans_ind == p[ans_ind]) {
            cout << nums[ans_ind] << " ";
            break;
        } else {
            cout << nums[ans_ind] << " ";
        }
        ans_ind = p[ans_ind];
    }

    return 0;
}

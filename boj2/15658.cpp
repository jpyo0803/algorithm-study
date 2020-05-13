//
// 연산자 끼워넣기 (2)
// Problem: https://www.acmicpc.net/problem/15658
//

#include <iostream>

using namespace std;
const int MAX{11};
const int INF{2000000000};
int N;
int nums[MAX];
int op[MAX - 1];
int op_num[4];

int max_res, min_res;
void solve(int nth) {
    if (nth == N - 1) {
        int res = nums[0];
        for (int i = 0; i < N - 1; i++) {
            if (op[i] == 0) res += nums[i + 1];
            else if (op[i] == 1) res -= nums[i + 1];
            else if (op[i] == 2) res *= nums[i + 1];
            else res /= nums[i + 1];
        }
        if (max_res < res) {
            max_res = res;
        }
        if (res < min_res) {
            min_res = res;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (op_num[i] > 0) {
            op_num[i] -= 1;
            op[nth] = i;
            solve(nth + 1);
            op_num[i] += 1;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> op_num[i];
    }

    max_res = -INF;
    min_res = INF;

    solve(0);

    cout << max_res << endl;
    cout << min_res << endl;
    return 0;
}
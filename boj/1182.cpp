//
// Subset sum
// Problem: https://www.acmicpc.net/problem/1182
//

#include <iostream>

using namespace std;
const int MAX_SIZE{20};
int N, S;
int nums[MAX_SIZE];

int ans = 0;

void solve(int nth, int prev_sum, int num_chosen) {
    if (nth == N) {
        if (prev_sum == S && num_chosen > 0) {
            ans += 1;
        }
        return;
    }

    solve(nth + 1, prev_sum, num_chosen);
    solve(nth + 1, prev_sum + nums[nth], num_chosen + 1);
}

int main() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) cin >> nums[i];

    solve(0, 0, 0);
    cout << ans;
    return 0;
}



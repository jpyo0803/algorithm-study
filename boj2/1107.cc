//
// Remote Controller
// https://www.acmicpc.net/problem/1107
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int N, M, num;
vector<int> nums;
int ans;
int num_chosen[7];

void comb(int nth, int limit) {
    if (nth == limit) {
        int multiplier = 1;
        int sum = 0;
        for (int i = 0; i < nth; i++) {
            sum += (num_chosen[i] * multiplier);
            multiplier *= 10;
        }
        ans = min(ans, abs(N - sum) + nth);
        return;
    }

    for (auto num : nums) {
        num_chosen[nth] = num;
        comb(nth + 1, limit);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;

    bool valid_nums[10];
    for (int i = 0; i < 10; i++) valid_nums[i] = true;
    for (int i = 0; i < M; i++) {
        cin >> num;
        valid_nums[num] = false;
    }

    for (int i = 0; i < 10; i++) {
        if (valid_nums[i]) {
            nums.push_back(i);
        }
    }


    ans = abs(N - 100);
    for (int i = 1; i <= 6; i++) {
        comb(0, i);
    }
    cout << ans;

    return 0;
}
//
// N and M 10
// Problem: https://www.acmicpc.net/problem/15664
//

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
const int MAX{8};
int N, M;
map<int, int> nums;
int chosen[MAX];

void solve(int nth, int prev) {
    if (nth == M) {
        for (int i = 0; i < M; i++) {
            printf("%d ", chosen[i]);
        }
        printf("\n");
        return;
    }

    for (auto& num : nums) {
        if (num.second > 0 && num.first >= prev) {
            chosen[nth] = num.first;
            num.second -= 1;
            solve(nth + 1, num.first);
            num.second += 1;
        }
    }
};

int main() {
    scanf("%d%d", &N, &M);

    int e;
    for (int i = 0; i < N; i++) {
        scanf("%d", &e);
        nums[e] += 1;
    }

    solve(0, 0);
    return 0;
}
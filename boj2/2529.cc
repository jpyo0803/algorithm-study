//
// Inequality
// Problem: https://www.acmicpc.net/problem/2529
//

#include <iostream>
#include <cstdlib>

using namespace std;
const int MAX{9};
char op[MAX];
int nums[MAX + 1];
int K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K;
    for (int i = 0; i < K; i++) cin >> op[i];

    int idx{0}, until{-1}, sn{9};
    while (true) {
        while (op[idx] == '<' && idx <= K) idx++;
        int bidx{idx};
        while (bidx > until) {
            nums[bidx--] = sn--;
        }
        if (idx == K) break;
        until = idx++;
    }
    for (int i = 0; i <= K; i++) cout << nums[i];
    cout << endl;

    idx = K - 1, until = K, sn = K;
    while (true) {
        while (op[idx] == '>' && idx >= 0) idx--;
        int bidx{idx + 1};
        while (bidx <= until) {
            nums[bidx++] = sn--;
        }
        if (idx == -1) break;
        until = idx--;
    }
    for (int i = 0; i <= K; i++) cout << nums[i];
    cout << endl;
    return 0;
}


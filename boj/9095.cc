//
// 1, 2, 3 Addition
// Problem: https://www.acmicpc.net/problem/9095
//

#include <iostream>

using namespace std;

int T, N;

int solve(int rem) {
    if (rem < 0) return 0;
    if (rem == 0) return 1;

    int loc_pos_way = 0;
    for (int i = 1; i < 4; i++) {
        loc_pos_way += solve(rem - i);
    }
    return loc_pos_way;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int i = 0; i < T; i++) {
        cin >> N;
        cout << solve(N) << endl;
    }
    return 0;
}



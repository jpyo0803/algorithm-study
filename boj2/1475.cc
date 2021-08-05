//
// Room Number
// Problem: https://www.acmicpc.net/problem/1475
//

#include <iostream>

using namespace std;
string N;
int left_num[10];
int main() {
    cin >> N;
    int set_count{0};
    for (auto digit : N) {
        if (left_num[digit - '0'] == 0) {
            if (digit == '6' && left_num[9] > 0) {
                left_num[9] -= 1;
            } else if (digit == '9' && left_num[6] > 0) {
                left_num[6] -= 1;
            } else {
                set_count += 1;
                for (int i = 0; i < 10; i++) {
                    left_num[i] += 1;
                }
                left_num[digit - '0'] -= 1;
            }
        } else {
            left_num[digit - '0'] -= 1;
        }
    }
    cout << set_count;
    return 0;
}
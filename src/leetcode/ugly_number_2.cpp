//
// Ugly Number II
// Problem : https://leetcode.com/problems/ugly-number-ii/
//

#include <iostream>
using namespace std;

int ugly_number[1690];

class Solution {
public:
    int smallest(int a, int b, int c) {
        int res = a;
        if (b < res) res = b;
        if (c < res) res = c;
        return res;
    }
    int nthUglyNumber(int n) {
        ugly_number[0] = 1;

        int order_2{0}, order_3{0}, order_5{0};
        int candidate_2{ugly_number[order_2] * 2},
                candidate_3{ugly_number[order_3] * 3},
                candidate_5{ugly_number[order_5] * 5};

        for (int i = 1; i < n; i++) {
            ugly_number[i] = smallest(candidate_2, candidate_3, candidate_5);

            if (ugly_number[i] == candidate_2) {
                order_2 += 1;
                candidate_2 = ugly_number[order_2] * 2;
            }
            if (ugly_number[i] == candidate_3) {
                order_3 += 1;
                candidate_3 = ugly_number[order_3] * 3;
            }
            if (ugly_number[i] == candidate_5) {
                order_5 += 1;
                candidate_5 = ugly_number[order_5] * 5;
            }
        }
        return ugly_number[n - 1];
    }
};
int main() {
    Solution s;
    cout << s.nthUglyNumber(1690);
    return 0;
}
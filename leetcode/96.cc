//
// 96. Unique Binary Search Trees
// Problem: https://leetcode.com/problems/unique-binary-search-trees/
//

#include <iostream>

using namespace std;

int catalan[20];

class Solution {
public:
    int numTrees(int n) {
        catalan[0] = 1; // C_0 = 1;

        for (int i = 1; i <= n; i++) {
            int catalan_i = 0;
            for (int j = 0; j < i; j++) {
                catalan_i += (catalan[j] * catalan[i - 1 - j]);
            }
            catalan[i] = catalan_i;
        }
        return catalan[n];
    }
};

int main() {
    Solution s;
    cout << s.numTrees(19);

    return 0;
}
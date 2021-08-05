//
// Flipped Addition
// Problem: https://www.acmicpc.net/problem/1357
//

#include <cstdio>
#include <vector>
#include <cmath>

int Rev(int num) {
    std::vector<int> digits;

    while (num) {
        digits.push_back(num % 10);
        num /= 10;
    }

    int ret = 0;
    for (int i = 0; i < digits.size(); i++) {
        ret += digits[i] * pow(10, digits.size() - i - 1);
    }
    return ret;
}

int X, Y;
int main() {
    scanf("%d%d", &X, &Y);
    printf("%d", Rev(Rev(X) + Rev(Y)));

    return 0;
}
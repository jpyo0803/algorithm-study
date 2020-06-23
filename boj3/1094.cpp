//
// Stick
// Problem: https://www.acmicpc.net/problem/1094
//

#include <cstdio>

using namespace std;
int X;
int main() {
    scanf("%d", &X);

    int s{64};
    int sum{64};
    int num_stick{1};
    while (X < sum) {
        int hs = s / 2;
        if (sum - hs < X) {
            num_stick += 1;
        } else {
            sum -= hs;
        }
        s = hs;
    }
    printf("%d", num_stick);

    return 0;
}


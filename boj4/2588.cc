//
// A + B - 2
// Link: https://www.acmicpc.net/problem/2558
//

#include <cstdio>
int main() {
    int ans = 0;
    for (int i = 0; i < 2; i++) {
        int x;
        scanf("%d", &x);
        ans += x;
    }
    printf("%d\n", ans);
}
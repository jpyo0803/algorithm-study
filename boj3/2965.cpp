//
// Three Kangaroos
// Problem: https://www.acmicpc.net/problem/2965
//

#include <cstdio>
int A, B, C;
int main() {
    scanf("%d%d%d", &A, &B, &C);
    int larger = (B - A) > (C - B) ? (B - A) : (C - B);
    printf("%d", larger - 1);
    return 0;
}
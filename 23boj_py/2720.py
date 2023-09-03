# 세탁소 사장 동혁
# https://www.acmicpc.net/problem/2720

import sys

T = int(sys.stdin.readline())

while T:
    T -= 1
    C = int(sys.stdin.readline())
    min_sum = int(1e9)
    ans = []
    for a in range((C // 25) + 1):
        for b in range(((C - 25 * a) // 10) + 1):
            for c in range(((C - 25 * a - 10 * b) // 5) + 1):
                d = C - 25 * a - 10 * b - 5 * c
                if a + b + c + d < min_sum:
                    ans = [a, b, c, d]

    for i in range(4):
        sys.stdout.write(f'{ans[i]} ')
    sys.stdout.write(f'\n')

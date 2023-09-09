# 가로수
# https://www.acmicpc.net/problem/2485

import sys


def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)


N = int(sys.stdin.readline())

gcd = -1
first = -1
last = -1
prev = 0

for i in range(N):
    x = int(sys.stdin.readline())
    if i == 0:
        first = x
    elif i == N - 1:
        last = x

    if i == 0:
        prev = x
    else:
        if gcd == -1:
            gcd = x - prev

        gcd = GCD(gcd, x - prev)
        prev = x

sys.stdout.write(f'{((last - first) // gcd) + 1 - N}\n')

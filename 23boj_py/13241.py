# 최소공배수
# https://www.acmicpc.net/problem/13241

import sys


def GCD(a, b):
    if b == 0:
        return a

    return GCD(b, a % b)


a, b = map(int, sys.stdin.readline().split())

k = GCD(a, b)

sys.stdout.write(f'{a * b // k}\n')

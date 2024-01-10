# 분수 합
# https://www.acmicpc.net/problem/1735

import sys


def GCD(a, b):
    if b == 0:
        return a
    return GCD(b, a % b)


a, b = map(int, sys.stdin.readline().split())
c, d = map(int, sys.stdin.readline().split())

num = a * d + c * b
den = b * d

k = GCD(num, den)

sys.stdout.write(f'{num // k} {den // k}\n')

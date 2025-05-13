# 진법 변환 2
# https://www.acmicpc.net/problem/11005

import sys


def Solve(N, B):
    q = N // B
    r = N % B

    if q != 0:
        Solve(q, B)

    digit = None
    if r >= 10:
        digit = chr((r - 10) + ord('A'))
    else:
        digit = chr(r + ord('0'))
    sys.stdout.write(f'{digit}')


N, B = map(int, sys.stdin.readline().split())
Solve(N, B)

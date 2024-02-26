# 캠핑
# https://www.acmicpc.net/problem/4796

import sys

x = 1
while True:
    L, P, V = map(int, sys.stdin.readline().split())
    if L == 0 and P == 0 and V == 0:
        break
    sys.stdout.write(
        f'Case {x}: {L * (V // P) + min(L, V % P)}\n')
    x += 1

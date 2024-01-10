# 보물
# https://www.acmicpc.net/problem/1026

import sys

N = int(sys.stdin.readline())
A = list(map(int, sys.stdin.readline().split()))
B = list(map(int, sys.stdin.readline().split()))

A = sorted(A)
B = sorted(B)

S = 0
for i in range(N):
    S += A[i] * B[N - i - 1]

sys.stdout.write(f'{S}\n')

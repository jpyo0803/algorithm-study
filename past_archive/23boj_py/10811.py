# 바구니 뒤집기
# https://www.acmicpc.net/problem/10811

import sys

N, M = map(int, sys.stdin.readline().split())

arr = [i + 1 for i in range(N)]

for i in range(M):
    x, y = map(int, sys.stdin.readline().split())
    x -= 1
    arr[x:y] = arr[x:y][::-1]

for e in arr:
    print(f'{e} ', end="")

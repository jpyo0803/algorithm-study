# 공 바꾸기
# https://www.acmicpc.net/problem/10813

import sys

N, M = map(int, sys.stdin.readline().split())

arr = [i + 1 for i in range(N)]

for i in range(M):
    x, y = map(int, sys.stdin.readline().split())
    tmp = arr[x - 1]
    arr[x - 1] = arr[y - 1]
    arr[y - 1] = tmp

for i in range(N):
    print(f'{arr[i]} ', end="")

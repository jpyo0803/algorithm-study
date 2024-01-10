# 공 넣기
# https://www.acmicpc.net/problem/10810

import sys

n, m = map(int, sys.stdin.readline().split())

arr = [0 for i in range(n + 1)]
for i in range(m):
    a, b, c = map(int, sys.stdin.readline().split())
    for j in range(a, b + 1):
        arr[j] = c

for i in range(1, n + 1):
    print(f'{arr[i]} ', end="")

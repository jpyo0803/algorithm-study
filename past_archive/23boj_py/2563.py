# 색종이
# https://www.acmicpc.net/problem/2563

import sys

N = int(input())

arr = [[False] * 100 for _ in range(100)]

while N > 0:
    x, y = map(int, sys.stdin.readline().split())
    for i in range(x, x + 10):
        for j in range(y, y + 10):
            arr[i][j] |= True
    N -= 1

ans = 0
for i in range(100):
    for j in range(100):
        if arr[i][j] == True:
            ans += 1

print(ans)

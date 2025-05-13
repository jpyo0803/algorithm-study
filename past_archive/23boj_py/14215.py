# 세 막대
# https://www.acmicpc.net/problem/14215

import sys

a, b, c = map(int, sys.stdin.readline().split())

ans = 0
for i in range(1, a + 1):
    for j in range(1, b + 1):
        for k in range(1, c + 1):
            arr = [i, j, k]
            arr.sort()

            if arr[0] + arr[1] <= arr[2]:
                continue

            ans = max(ans, i + j + k)

sys.stdout.write(f'{ans}\n')

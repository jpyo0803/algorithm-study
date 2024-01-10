# 에라토스테네스의 체
# https://www.acmicpc.net/problem/2960

import sys

N, K = map(int, sys.stdin.readline().split())

chk = [False for _ in range(N + 1)]

ans = -1

for i in range(2, N + 1):
    if chk[i] == True:
        continue
    j = i
    while j <= N:
        if chk[j] == False:
            chk[j] = True
            K -= 1
            if ans == -1 and K == 0:
                ans = j
        j += i

print(ans)

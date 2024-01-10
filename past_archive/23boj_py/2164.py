# 카드2
# https://www.acmicpc.net/problem/2164

import sys

N = int(sys.stdin.readline())

head = tail = 0
que = []

for i in range(1, N + 1):
    que.append(i)
    tail += 1

while tail - head > 1:
    que.append(que[head + 1])
    tail += 1
    head += 2

sys.stdout.write(f'{que[head]}')

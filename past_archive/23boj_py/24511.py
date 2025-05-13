# queuestack
# https://www.acmicpc.net/problem/24511

import sys

N = int(sys.stdin.readline())

types = list(map(int, sys.stdin.readline().split()))
vals = list(map(int, sys.stdin.readline().split()))

que = []
head = tail = 0

for i in range(len(types))[::-1]:
    if types[i] == 0:
        que.append(vals[i])
        tail += 1

M = int(sys.stdin.readline())
reqs = list(map(int, sys.stdin.readline().split()))
for req in reqs:
    if head != tail:
        sys.stdout.write(f'{que[head]} ')
        head += 1
        que.append(req)
        tail += 1
    else:
        sys.stdout.write(f'{req} ')

sys.stdout.write('\n')

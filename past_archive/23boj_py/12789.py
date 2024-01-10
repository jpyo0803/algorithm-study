# 오키도키 간식드리미
# https://www.acmicpc.net/problem/12789

import sys

N = int(sys.stdin.readline())
line = list(map(int, sys.stdin.readline().split()))

ok = True

i = 0
desire = 1

stk = []

while True:
    x = False
    y = False
    if i < N and line[i] == desire:
        x = True
    if len(stk) > 0 and stk[len(stk) - 1] == desire:
        y = True

    if x == True:
        i += 1
        desire += 1
    elif y == True:
        stk.pop()
        desire += 1
    else:
        if i == N:
            break
        else:
            stk.append(line[i])
            i += 1

sys.stdout.write(f'{"Nice" if desire == N + 1 else "Sad"}')

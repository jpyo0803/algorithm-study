# 스택 2
# https://www.acmicpc.net/problem/28278

import sys

N = int(sys.stdin.readline())

stk = []

while N > 0:
    cmd = list(map(int, sys.stdin.readline().split()))
    x = cmd[0]
    y = -1
    if len(cmd) > 1:
        y = cmd[1]

    if x == 1:
        stk.append(y)
    elif x == 2:
        if len(stk) == 0:
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'{stk[len(stk) - 1]}\n')
            stk.pop()
    elif x == 3:
        sys.stdout.write(f'{len(stk)}\n')
    elif x == 4:
        sys.stdout.write(f'{1 if len(stk) == 0 else 0}\n')
    else:
        if len(stk) == 0:
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'{stk[len(stk) - 1]}\n')

    N -= 1

# 덱 2
# https://www.acmicpc.net/problem/28279

import sys

N = int(sys.stdin.readline())

deq = [0 for _ in range(0, 2 * N + 10)]

head = N + 5
tail = head + 1

while N > 0:
    cmd = list(map(int, sys.stdin.readline().split()))
    if cmd[0] == 1:
        deq[head] = cmd[1]
        head -= 1
    elif cmd[0] == 2:
        deq[tail] = cmd[1]
        tail += 1
    elif cmd[0] == 3:
        if head + 1 == tail:
            sys.stdout.write(f'-1\n')
        else:
            head += 1
            sys.stdout.write(f'{deq[head]}\n')
    elif cmd[0] == 4:
        if head + 1 == tail:
            sys.stdout.write(f'-1\n')
        else:
            tail -= 1
            sys.stdout.write(f'{deq[tail]}\n')
    elif cmd[0] == 5:
        sys.stdout.write(f'{tail - head - 1}\n')
    elif cmd[0] == 6:
        sys.stdout.write(f'{1 if tail - head - 1 == 0 else 0}\n')
    elif cmd[0] == 7:
        if head + 1 == tail:
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'{deq[head + 1]}\n')
    elif cmd[0] == 8:
        if head + 1 == tail:
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'{deq[tail - 1]}\n')
    N -= 1

# 큐 2
# https://www.acmicpc.net/problem/18258

import sys

N = int(sys.stdin.readline())

que = []
head = 0
tail = 0
# head == tail -> empty

while N > 0:
    cmd = sys.stdin.readline().split()
    if cmd[0] == "push":
        que.append(int(cmd[1]))
        tail += 1
    elif cmd[0] == "pop":
        if head == tail:
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'{que[head]}\n')
            head += 1
    elif cmd[0] == "size":
        sys.stdout.write(f'{tail - head}\n')
    elif cmd[0] == "empty":
        sys.stdout.write(f'{1 if head == tail else 0}\n')
    elif cmd[0] == "front":
        if head == tail:
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'{que[head]}\n')
    else:
        if head == tail:
            sys.stdout.write(f'-1\n')
        else:
            sys.stdout.write(f'{que[tail - 1]}\n')

    N -= 1

# 윷놀이
# https://www.acmicpc.net/problem/249이

import sys

lines = sys.stdin.read().splitlines()

for line in lines:
    nums = list(map(int, line.split()))

    zc = 0
    oc = 0
    for num in nums:
        if (num == 0):
            zc += 1
        else:
            oc += 1

    if zc == 1 and oc == 3:
        print('A')
    elif zc == 2 and oc == 2:
        print('B')
    elif zc == 3 and oc == 1:
        print('C')
    elif zc == 4:
        print('D')
    else:
        print('E')

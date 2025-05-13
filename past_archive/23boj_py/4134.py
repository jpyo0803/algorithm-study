# 다음 소수
# https://www.acmicpc.net/problem/4134

import sys
import math

T = int(sys.stdin.readline())

while T > 0:
    x = int(sys.stdin.readline())
    y = x
    if x >= 2:
        while True:
            ok = True
            for i in range(2, int(math.sqrt(y)) + 1):
                if y % i == 0:
                    ok = False
                    break
            if ok == True:
                break
            else:
                y += 1
    else:
        y = 2

    sys.stdout.write(f'{y}\n')
    T -= 1

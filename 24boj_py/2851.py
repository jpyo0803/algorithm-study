# 슈퍼 마리오
# https://www.acmicpc.net/problem/2851

import sys

# read until EOF, integer will be given line by line
# and store them in a list
mushrooms = [int(sys.stdin.readline()) for _ in range(10)]

s = 0
for mushroom in mushrooms:
    tmp = s + mushroom
    if abs(tmp - 100) <= abs(s - 100):
        s = tmp
    else:
        break

sys.stdout.write(f'{s}\n')
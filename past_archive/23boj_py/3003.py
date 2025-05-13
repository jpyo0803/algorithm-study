# 킹, 퀸, 룩, 비숍, 나이트, 폰
# https://www.acmicpc.net/problem/3003

import sys

a, b, c, d, e, f = map(int, sys.stdin.readline().split())
print(f'{1 - a} {1 - b} {2 - c} {2 - d} {2 - e} {8 - f}')

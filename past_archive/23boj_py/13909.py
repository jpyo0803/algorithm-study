# 창문 닫기
# https://www.acmicpc.net/problem/13909

import sys

N = int(sys.stdin.readline())

x = 1
while True:
    if x * x <= N and N < (x + 1) * (x + 1):
        break
    x += 1

sys.stdout.write(f'{x}\n')

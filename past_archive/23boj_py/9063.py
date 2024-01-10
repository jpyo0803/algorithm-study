# 대지
# https://www.acmicpc.net/problem/9063

import sys

N = int(sys.stdin.readline())

top = -1e5
bot = 1e5
left = 1e5
right = -1e5
while N > 0:
    x, y = map(int, sys.stdin.readline().split())

    top = max(top, y)
    bot = min(bot, y)
    left = min(left, x)
    right = max(right, x)

    N -= 1

sys.stdout.write(f"{(top - bot)*(right - left)}\n")

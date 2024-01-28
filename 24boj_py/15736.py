# 청기백기
# https://www.acmicpc.net/problem/15736

import sys
N = int(sys.stdin.readline())

ans = 0
i = 1
while i * i <= N:
  ans += 1
  i += 1

sys.stdout.write(f'{ans}\n')
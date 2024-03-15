# 지뢰찾기
# https://www.acmicpc.net/problem/4108

import sys

def CountBomb(arr, r, c, R, C):
  cnt = 0
  for i in range(-1, 2):
    for j in range(-1, 2):
      if i == 0 and j == 0:
        continue
      if r + i >= 0 and r + i < R and c + j >= 0 and c + j < C:
        if arr[r + i][c + j] == '*':
          cnt += 1
  return cnt

R, C = map(int, sys.stdin.readline().split())


while R != 0 and C != 0:
  arr = [[' ']*C for _ in range(R)]
  for i in range(R):
    line = sys.stdin.readline()
    for j in range(C):
      arr[i][j] = line[j]

  for i in range(R):
    for j in range(C):
      if arr[i][j] == '*':
        sys.stdout.write('*')
      else:
        sys.stdout.write(f'{CountBomb(arr, i, j, R, C)}')
    sys.stdout.write('\n')

  R, C = map(int, sys.stdin.readline().split())

# 삼각형 외우기
# https://www.acmicpc.net/problem/10101

import sys

a = int(sys.stdin.readline())
b = int(sys.stdin.readline())
c = int(sys.stdin.readline())

total = sum([a, b, c])
if total != 180:
    sys.stdout.write(f'Error\n')
elif a == b and b == c:
    sys.stdout.write(f'Equilateral\n')
elif a == b or b == c or a == c:
    sys.stdout.write(f'Isosceles\n')
else:
    sys.stdout.write(f'Scalene\n')

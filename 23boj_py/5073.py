# 삼각형과 세 변
# https://www.acmicpc.net/problem/5073

import sys

while True:
    a, b, c = map(int, sys.stdin.readline().split())
    if a == 0 and b == 0 and c == 0:
        break
    max_val = max(a, b, c)
    sum_other = a + b + c - max_val
    if max_val >= sum_other:
        print("Invalid")
    else:
        if a == b and b == c:
            print("Equilateral")
        elif a == b or b == c or a == c:
            print("Isosceles")
        else:
            print("Scalene")

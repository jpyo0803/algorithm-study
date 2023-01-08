# 열 개씩 끊어 출력하기
# https://www.acmicpc.net/problem/11721

import sys

line = input()

count = 0

str = ""
for i in range(len(line)):
    if count == 10:
        print(str)
        str = ""
        count = 0

    str += line[i]
    count += 1

print(str)

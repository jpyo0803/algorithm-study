# 별 찍기 - 3
# https://www.acmicpc.net/problem/2440

n = int(input())

for i in reversed(range(n)):
    for j in range(i + 1):
        print("*", end='')
    print(end='\n')

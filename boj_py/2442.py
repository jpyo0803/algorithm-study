# 별 찍기 - 5
# https://www.acmicpc.net/problem/2442

def Abs(x):
    if x < 0:
        return -x
    else:
        return x


N = int(input())

for i in range(N):
    for j in range(N + i):
        if Abs(N - 1 - j) <= i:
            print("*", end='')
        else:
            print(" ", end='')
    print(end='\n')

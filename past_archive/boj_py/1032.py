# 명령 프롬프트
# https://www.acmicpc.net/problem/1032

N = int(input())

names = []
for i in range(N):
    names.append(input())

name_len = len(names[0])

valid_arr = [True for i in range(name_len)]

for i in range(name_len):
    for j in range(len(names) - 1):
        if (names[j][i] != names[j + 1][i]):
            valid_arr[i] = False
            break

for i in range(len(valid_arr)):
    if valid_arr[i] == True:
        print(names[0][i], end='')
    else:
        print('?', end='')

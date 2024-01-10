# 진법 변환
# https://www.acmicpc.net/problem/2745

N, B = input().split()
B = int(B)

num = 0
exp = 0
for digit in N[::-1]:
    if digit >= '0' and digit <= '9':
        digit = ord(digit) - ord('0')
    else:
        digit = ord(digit) - ord('A') + 10
    num += pow(B, exp) * digit
    exp += 1

print(num)

# 알파벳 개수
# https://www.acmicpc.net/problem/10808

def IsAlpha(ch):
    return ch >= 'a' and ch <= 'z'


alpha_count = [0 for i in range(26)]

S = input()

for ch in S:
    if IsAlpha(ch):
        alpha_count[ord(ch) - 97] += 1

for i in alpha_count:
    print(i, end=' ')

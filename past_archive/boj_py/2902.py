# KMP는 왜 KMP일까?
# https://www.acmicpc.net/problem/2902

S = input()

was_hyphen = True

ans = ""

for ch in S:
    if was_hyphen == True:
        ans += ch
        was_hyphen = False
    else:
        if ch == '-':
            was_hyphen = True

print(ans)

# 10부제
# https://www.acmicpc.net/problem/10797

N = int(input())

nums = list(map(int, input().split()))

count = 0
for num in nums:
    if num == N:
        count += 1

print(count)

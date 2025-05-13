# 중앙 이동 알고리즘
# https://www.acmicpc.net/problem/2903

N = int(input())

num_pts = 4
s = 1
while N > 0:
    num_sqr = s ** 2
    num_pts += num_sqr * 5 - 2 * s * (s - 1)
    s *= 2
    N -= 1

print(num_pts)

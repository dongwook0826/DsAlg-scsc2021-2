import sys

N = int(sys.stdin.readline())

res = 1

for i in range(N):
    res *= (i+1)

print(res)
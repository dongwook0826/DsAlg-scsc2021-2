import sys

N = int(sys.stdin.readline())
l = set()
l_add = l.add

for _ in range(N):
    word = str(sys.stdin.readline())[0:-1]
    l_add((len(word), word))

l = list(l)
l.sort()
for i in l:
    print(i[1])
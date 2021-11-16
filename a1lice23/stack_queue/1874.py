import sys

n = int(sys.stdin.readline())

stack = []
prtL = []
stack_add = stack.append
prtL_add = prtL.append
end = 1
flag = True

for i in range(n):
    s = int(sys.stdin.readline())
    while end <= s:
        stack_add(end)
        prtL_add('+')
        end += 1
    if stack[-1] == s:
        stack.pop()
        prtL_add('-')
    else:
        flag = False
if flag:
    for i in prtL:
        print(i)
else:
    print('NO')
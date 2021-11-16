s = input()

bracket = {'(':')','[':']'}

while(s != "."):
    stack = []
    for ch in s:
        if ch == '(' or ch == '[':
            stack.append(ch)
        elif ch == ')' or ch == ']':
            if len(stack) == 0 or bracket.get(stack[-1]) != ch:
                print("no")
                break
            else:
                del stack[-1]
    else:
        if stack:
            print("no")
        else:
            print("yes")
    
    s = input()
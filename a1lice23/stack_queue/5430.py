T = int(input())

while T:
    
    mes = input()
    n = int(input())
    s = input()
    seq = s[1:-1].split(',')

    l, r, sign = 0, 0, 0
    for c in mes:
        if c == 'R':
            sign = 1 - sign
        elif c == 'D':
            if sign == 0:
                l += 1
            else:
                r += 1
    if l + r <= n:
        seq = seq[l:n-r]
        if(sign):
            seq.reverse()

        print('[', end='')
        print(*seq, sep=',', end='')
        print(']')
    else:
        print("error")
    
    T -= 1
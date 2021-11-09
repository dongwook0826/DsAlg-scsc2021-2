def print_sierpinski_stars(k):
    empty_str = [' ']
    for _ in range(k-1):
        empty_str.append(empty_str[-1]*3)
    ternary = [0]*k
    ternary[0] = -1
    for _ in range(3**k):
        ternary[0] += 1
        line = '*'
        for d in range(k):
            if ternary[d] == 3:
                ternary[d+1] += 1
                ternary[d] = 0
            if ternary[d] == 1:
                line = line + empty_str[d] + line
            else:
                line *= 3
        print(line)

if __name__ == "__main__":
    N = int(input())
    n = 0
    while N>1:
        N //= 3
        n += 1
    print_sierpinski_stars(n)

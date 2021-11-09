def hanoi_seq(n, a, b, c):
    if n <= 0: return
    hanoi_seq(n-1, a, c, b)
    print(f"{a} {b}")
    hanoi_seq(n-1, c, b, a)

if __name__ == "__main__":
    n = int(input())
    print(2**n - 1)
    hanoi_seq(n, 1, 3, 2)

# Problem 10870

def fib_tc(n, f1, f2):
    return fib_tc(n-1, f2, f1+f2) if n > 1 else f2

def fib(n):
    return fib_tc(n, 0, 1) if n >= 1 else 0

if __name__  == "__main__":
    print(fib(int(input())))

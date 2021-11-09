def factorial(n, prod):
    return factorial((n-1), n*prod) if n > 1 else prod

if __name__ == "__main__":
    print(factorial(int(input()), 1))

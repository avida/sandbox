#!/usr/bin/env python3
import sys

def fib(n):
    if n == 0:
        return 0
    if n in [1, 2]:
        return 1
    return fib(n - 2) + fib(n - 1)

def fib_gen(n):
    for i in range(1, n+1):
        yield fib(i)

def fib_gen2(n):
    a, b = 1, 1
    for _ in range(n):
        yield a
        a, b = b, a + b

for i in fib_gen(10):
    sys.stdout.write(f"{i} ")
print()

print(list(fib_gen2(10)))


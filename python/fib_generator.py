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

for i in fib_gen(10):
    sys.stdout.write(f"{i} ")
print()

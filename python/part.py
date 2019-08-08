#!/usr/bin/env python3
from functools import partial

def func(a):
    print(f" par is {a}")

class Class:
    def __init__(self):
        self.num = 42

    def func(self, a):
        print(f" par is {a}, num is {self.num}")

f = partial(func, 3)
f()
c = Class()
f = partial(Class.func, c , 6)
f()

#!/usr/bin/env python3

class Indexer:
    def __index__(self):
        return 2

a = list(range(0,10))
print(f"a is {a}")
print(f"First 2 a' elements: {a[:2]}")
print(f"{a[::Indexer()]}")

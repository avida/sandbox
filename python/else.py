#!/usr/bin/env python3
import random

print("hi")

for i in range(3):
    if i is random.randint(0,3):
        print("Found random number")
        break
else:
    print("Random number not found")

try:
    a = list(range(3))
    b = a[3]
except:
    print("except block")
else:
    print("except else block")
finally:
    print("finally block")


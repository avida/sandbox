#!/usr/bin/env python3

print("hi")
a = {}
for i in range(0,10):
   a[i] = str(i)
print(a)

print(dict(filter(lambda x: x[1] != "3", a.items())))


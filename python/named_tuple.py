#!/usr/bin/env python3

from collections import namedtuple

MyTuple = namedtuple('MyTuple', 'a b c')
t = MyTuple(1,2,3)
print("hi")
print(f"{t.a}")

#!/usr/bin/env python3
import traceback

def fun():
    print("hi")
    raise Exception("asda")
try:
    print("asads")
    fun()
except Exception as e:
    s = traceback.format_exc()
    print(s)
    print("bye")


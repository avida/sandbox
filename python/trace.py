#!/usr/bin/env python3
import traceback

def fun():
    print("hi")
    raise Exception("asda")
try:
    print("asads")
    fun()
except Exception as e:
    traceback.print_exc()
    print("by")


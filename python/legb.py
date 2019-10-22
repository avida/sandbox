#!/usr/bin/env python3

X = "global"
class A:
    X = "class var"
    def __foo(self):
        print("This is a private method")

    def m(self):
        def subf():
            X = "subf"
            print(f"Hi {X}") 
        print(f"Hi {X}")
        subf()

a = A()
a.m()

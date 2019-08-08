#!/usr/bin/env python3

class SimpleObject:
    def __init__(self):
        self.b = "b"

    def __getattr__(self, attr):
        print("__getattr__ ", attr)
        return "a value"

    def __getattribute__(self, attr):
        print("__getattribute__ ", attr)
        return "a value"

    def __setattr__(self, attr, value):
        print(f"__setattr__ {attr}: {value}")

class SetAttr:
    def __setattr__(self, attr, value):
        print(f"__setattr__ {attr}: {value}")
        self.__dict__[attr] = value

s = SimpleObject()
print(s.aaa)
print(s.b)
s.dummy = "as"
s = SetAttr()
s.qqwe = lambda : print("labmda call")
s.qqwe()

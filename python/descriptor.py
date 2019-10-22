#!/usr/bin/env python3

class Desc:
    def __delete__(self, instance):
        print("__delete__")

    def __get__(self, instance, owner):
        print(f"__get__ {instance}, {owner}")
        return 23

    def __set__(self, instance, value):
        print(f"__set__ {instance}, {value}")
class A:
    asd = Desc()

print("Hi")
a = A()
a.asd = 29
a.asd = None
del a.asd
print(f"{a.asd}")

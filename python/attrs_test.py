#!/usr/bin/env python3
import attr

@attr.s
class SomeClass:
    a = attr.ib()
    @a.validator
    def check(self, attribute, value):
        print(f"{attribute} = {value}")
    ss = attr.ib(default="Hi")
s = SomeClass(a = 1)

print("Hi")
print(f"{s}")
print(f"{attr.asdict(s)}")

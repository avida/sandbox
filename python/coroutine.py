#!/usr/bin/env python3
def print_name():
    try:
        while True:
            n = (yield)
            print(n)
            if n is "Bingo":
                yield 12
                break
    except StopIteration:
        print(f"Iteration stopped")
    except GeneratorExit:
        print(f"Generator exited")
    
c = print_name()
next(c)
c.send("first line")
c.send("second line")
try:
    print("Result is {}".format(c.send("Bingo")))
    c.send("Bingo")
except StopIteration:
    print("Stop Iteration")
    pass
c.close()

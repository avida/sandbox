#!/usr/bin/env python3
from multiprocessing import Process
from threading import Thread
import time 
global_var = 2

def process_body():
    print("process spawned")
    while True:
        time.sleep(1)
        print(f"ping {global_var}")

print('hi')
p = Thread(target=process_body)
p.start()
time.sleep(3)
print("var changed")
global_var = 53
p.join()


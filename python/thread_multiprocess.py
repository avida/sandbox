#!/usr/bin/env python3
import time 

INITIAL_VAL = 2
global_var = INITIAL_VAL

def process_body():
    print("process spawned")
    global global_var
    for _ in range(2):
        time.sleep(1)
        print(f"value is {global_var}")

def spawn_thread():
    from threading import Thread
    global global_var
    global_var = INITIAL_VAL
    p = Thread(target=process_body)
    p.start()
    time.sleep(1)
    global_var = 53
    print(f"value changed to {global_var}")
    p.join()
    
def spawn_process():
    from multiprocessing import Process
    global global_var
    global_var = INITIAL_VAL
    p = Process(target=process_body)
    p.start()
    time.sleep(1)
    global_var = 53
    print(f"value changed to {global_var}")
    p.join()
    
print("spawn thread")
spawn_thread()
print("spawn process")
spawn_process()

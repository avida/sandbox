#!/usr/bin/env python3
import asyncio
import time

def some_func():
    print("Start")
    time.sleep(2)
    print('ooops')
    return 42

loop = asyncio.get_event_loop()
t = loop.run_in_executor(None, some_func)
loop.run_until_complete(t)
loop.close()

#!/usr/bin/env python3
import asyncio
import threading 
import time

def other_thread():
    print("Start thread")
    print(f"{'thread tid':<12}: {threading.get_ident()}")
    time.sleep(1)
    return 42

async def task():
    print(f"{'task tid':<12}: {threading.get_ident()}")
    await asyncio.sleep(2)
    return "Finished"

loop = asyncio.get_event_loop()
print(f"{'main tid':<12}: {threading.get_ident()}")
t = loop.run_in_executor(None, other_thread)
r = loop.run_until_complete(asyncio.gather(t, task()))
print(f"Results: {r}")
loop.close()

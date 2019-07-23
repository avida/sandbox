#!/usr/bin/env python3

import asyncio
import sys 

def got_data():
    line = sys.stdin.readline().strip()
    global loop
    print(f"Input line is {line}")

async def long_wait():
    await asyncio.sleep(10000)

loop = asyncio.get_event_loop()
loop.add_reader(sys.stdin, got_data)
try:
    loop.run_until_complete(long_wait())
except KeyboardInterrupt:
    print("Interrupted by user")





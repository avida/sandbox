#!/usr/bin/env python3
import asyncio

def decor(f):
    async def wrapper(*args):
        await f()
    return decor

async def task():
    await asyncio.sleep(1)
    return 3
loop = asyncio.get_event_loop()
r = loop.run_until_complete(task())
print(r)


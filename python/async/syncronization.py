#!/usr/bin/env python3
import asyncio

async def printer(line, lock):
    with(await lock):
        for _ in range(2):
            print(line)
            await asyncio.sleep(.2)

def try_lock(loop):
    lock = asyncio.Lock()
    loop.run_until_complete(asyncio.gather( 
            printer("1", lock), 
            printer("2", lock)))

def try_future(loop):
    future = asyncio.Future()
    print("set future")
    asyncio.ensure_future(future)
    loop.call_later(1, lambda: future.set_result(2))
    loop.run_until_complete(future)
    print("try future completed")


loop = asyncio.get_event_loop()
try_lock(loop)
try_future(loop)

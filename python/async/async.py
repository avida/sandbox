#!/usr/bin/env python3
import asyncio
import time

async def main(loop):
    print('Hi')
    await asyncio.sleep(1)
    print('Bye')
    #loop.stop()

def some_func():
    time.sleep(2)
    print('ooops')
    return 42

loop = asyncio.get_event_loop()
loop.run_in_executor(None, some_func)
loop.create_task(main(loop))
loop.run_forever()
loop.close()

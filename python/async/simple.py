#!/usr/bin/env python3
import asyncio

async def main():
    print('Hi')
    await asyncio.sleep(1)
    print('Bye')

async def main2():
    print('Hi1')
    await asyncio.sleep(1)
    print('Bye1')

loop = asyncio.get_event_loop()
loop.run_until_complete(main())
loop.close()

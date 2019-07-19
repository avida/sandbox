#!/usr/bin/env python3
import asyncio

async def main(loop):
    print('Hi')
    await asyncio.sleep(1)
    print('Bye')

loop = asyncio.get_event_loop()
loop.run_until_complete(main(loop))
loop.close()

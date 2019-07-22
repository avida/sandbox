#!/usr/bin/env python3
import asyncio
import time

async def main(loop):
    print('Hi')
    await asyncio.sleep(.1)
    print('Bye')
    loop.stop()

async def calc(a, b):
    await asyncio.sleep(.2)
    return a + b

async def calculate(a, b):
    await calc(a, b)

async def run(cmd):
    proc = await asyncio.create_subprocess_shell(cmd,
    stdout = asyncio.subprocess.PIPE)
    stdout, stderr = await proc.communicate()
    print(f"{stdout}\n{stderr}")

loop = asyncio.get_event_loop()
print("schedule task and stop event loop")
loop.create_task(main(loop))
loop.run_forever()
print("run chain of tasks")
loop.run_until_complete(calculate(2, 5))
print("run subprocess task")
loop.run_until_complete(run("sleep 1s"))

loop.close()

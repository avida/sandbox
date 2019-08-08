#!/usr/bin/env python3
import asyncio
import os

async def kill_proc(p, stdin):
    await asyncio.sleep(1)
    #p.kill()
    for i in "abcd":
        stdin.write(i.encode())
    await asyncio.sleep(1)
    p.kill()

async def run_cmd(*cmd, loop):
    p = await asyncio.create_subprocess_exec(*cmd, 
        stdout = asyncio.subprocess.PIPE, 
        stdin=asyncio.subprocess.PIPE,
        stderr=asyncio.subprocess.PIPE)
    print(f"pid is {p.pid}")
    loop.create_task(kill_proc(p, p.stdin))
    while True:
        line = await p.stdout.readline()
        if not line:
            break
        print(f"{line.decode().strip()}")

loop = asyncio.get_event_loop()
loop.run_until_complete(run_cmd("./read_char.sh", loop=loop))


#!/usr/bin/env python3
import asyncio


async def task():
    print("Wait")
    try:
        await asyncio.sleep(3)
        print("Hi")
    except Exception as e:
        print(f"Exception {type(e)} occured: {e}")
    print("bb")
    
def throw_except(loop):
    def exeption_hndl(loop, context):
        print(f"exception handler {context}")
        context["future"].cancel()
        loop.stop()
    loop.set_exception_handler(exeption_hndl)
    t = task()
    async def throw(t):
        await asyncio.sleep(1)
        t.throw(Exception("cancelled!"))
    loop.create_task(throw(t))
    loop.run_until_complete(t)

def set_except(loop):
    async def set_expt(t):
        await asyncio.sleep(1) 
        t.set_exception(Exception("exception set"))
    t = loop.create_task(task())
    loop.create_task(set_expt(t))
    loop.run_forever()

def cancel_task(loop):
    async def cancel_task(task):
        await asyncio.sleep(1)
        task.cancel()
    
    t = loop.create_task(task()) 
    loop.create_task(cancel_task(t))
    loop.run_until_complete(t)

loop = asyncio.get_event_loop()
#cancel_task(loop)
set_except(loop)
#throw_except(loop)

#!/usr/bin/env python3
import asyncio
import aiohttp

async def fetch(session, url):
    async with session.get(url) as response:
        return await response.text()

async def main():
    async with aiohttp.ClientSession() as session:
        html = await fetch(session, 'http://google.com')
        print(html)

print("hi")
loop = asyncio.get_event_loop()
loop.run_until_complete(main())

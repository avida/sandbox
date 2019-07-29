#!/usr/bin/env python3
from aiohttp import web 

async def handle(request):
    name = request.match_info.get('')
    print(f"{request.path}")
    return web.Response(text="hello")

app = web.Application()
app.add_routes([
    web.get('/', handle),
    web.get('/{name}', handle)
])

web.run_app(app)

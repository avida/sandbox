#!/usr/bin/env python3

import shelve

with shelve.open("s.db") as db:
    for i in range(0, 5000):
        db[f"{i}"] = f"i value: {i}"
with shelve.open("s.db") as db:
    print(f"db len: {len(db.keys())}")
    print(f"{list(db.values())}")

#!/usr/bin/env python3

from dictdiffer import diff
import shelve

d = shelve.open("s.db")
for i in range(0, 500):
    d[f"{i}"] = {"name": f"JOe {i}", "email": f"test{i}@gmai.com"}

c = dict(d).copy()
c["20"] = {"name": "joe", "email": "ssssss@dd"}
c["2001000"] = {"name": "putin", "email": "ssssss@dd"}
del c["250"]
del c["251"]
c["1999"] = {"name": "putin", "email": "ssssss@dd"}
c["2000"] = {"name": "putin", "email": "ssssss@dd"}
c[f"100"] = {"email": f"test100@gmai.com", "name": f"JOe 100", }
for dff in diff(d, c, expand = False):
    print(dff)

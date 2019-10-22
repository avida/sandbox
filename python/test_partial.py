#!/usr/bin/env python3
from functools import partial

from collections import namedtuple

Row = namedtuple("Row", "values")

def _convert_to_dict(columns: list, row: Row) -> dict:
    print(row)
    print(columns)
    return dict(zip(columns, row.values))


columns = ["c1", "c2"]
rows = [
Row(["adsf", "112"]),
Row(["sf", "12"]),
]
print("hi")
print( list(map (
    partial(_convert_to_dict, columns), rows
)))

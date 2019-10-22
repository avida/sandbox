#!/usr/bin/env python3
import csv
from functools import reduce
from gzip import GzipFile
from io import TextIOWrapper

filepath = "/home/dima/Downloads/get_info_fields.csv"
print("hi")

tables_map = {}
with TextIOWrapper(GzipFile("./get_info_fields.csv.gz")) as f:
    csv_reader = csv.reader(f)
    for row in csv_reader:
        print(row)
        continue
        db = row["DataBaseName"]
        if db not in tables_map:
            tables_map[db] = set()
        tables_map[db].add(row["TableName"])
q = "SELECT * FROM\n"

prev_alias = None
for db, tables  in tables_map.items():
    als = set()
    for table in tables:
        tb = f"{db}.{table}"
        tb = f"DLIVEACCPADB.{table}"
        alias = table.split("_")
        alias = reduce(lambda x, y: x + y[0], alias, "")
        while alias in als:
            alias+="2"
        if prev_alias is None:
            q += f"{tb} {alias}\n"
        else:
            q += f"""FULL JOIN {tb} {alias}
ON
{alias}.lasso_cust_id= {prev_alias}.lasso_cust_id
"""
        prev_alias = alias
        als.add(alias)
    q+=f"WHERE\n"
    conds = []
    for a in als:
        conds.append(f"{a}.lasso_cust_id='201-ARCHTICS UNODAK-292990'")
    q+= " or \n".join(conds)

    with open(f"{db}.txt", "w") as f:
        f.write(q)
    q = "SELECT * FROM\n"
    prev_alias = None

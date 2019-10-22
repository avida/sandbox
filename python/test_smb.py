#!/usr/bin/env python3
from smb.SMBConnection import SMBConnection
from smb.base import SharedDevice
from datetime import datetime

usr = "dima"
pwd = "1888"
name = "127.0.0.1"
conn = SMBConnection(usr , pwd, "", "", use_ntlm_v2=True,
                                                  is_direct_tcp=True) 
if not conn.connect(name):
    print("Cannot connect")
    exit(1)

for d in conn.listPath("MyShare", '/'):
    print(f"{d.filename}, {datetime.utcfromtimestamp(d.create_time)}")


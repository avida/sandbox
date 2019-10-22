#!/usr/bin/env python3
from crontab import CronTab
from datetime import datetime, timedelta

print("hi")

entry = CronTab("* * * * *")
print(f"{entry.next(default_utc=True)}")
td = timedelta(seconds=abs(entry.previous(default_utc=True)))
print(f"{abs(entry.previous(default_utc=True))}")
print(f"{td}")


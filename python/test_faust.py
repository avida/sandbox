#!/usr/bin/env python3
import faust
import rocksdb

app = faust.App('test-app', broker='kafka://localhost', topic_partitions=1)
my_topic = app.topic('MyTopic', value_type=bytes, value_serializer="raw")

TABLE_NAME = "MyTable"

db = rocksdb.DB("my.db")

def msg():
    db.put("asfsdf", "sdfd")

@app.agent(my_topic)
async def process(stream):
    async for fact in stream:
        print(f"received {fact}")
        msg()
print ("hi")

print(db.keys())
for k in table:
    print(k)

if __name__ == "__main__":
    app.main()


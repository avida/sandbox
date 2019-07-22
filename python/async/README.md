This is python asincio library examples.

It require python 3.6 to run. See python 3.6 [asyncio reference](https://docs.python.org/3.6/library/asyncio.html)

* [simple.py](./simple.py)
Queues up a simple coroutine that waits for 1 sec and returns

```
Hi
Bye
```

* [task.py](./task.py)

Basic asyncio tasks exmaple
```
schedule task and stop event loop
Hi
Bye
run chain of tasks
run subprocess task
b''
None
```
* [synchroniztaion.py](./synchroniztaion.py)
Lock and future async synchronization primitives
```
2
2
1
1
set future
try future completed
```

* [external_executor.py](./external_executor.py)

Run task in other thread and wait until it completed
```
main tid: 139921831233280
Start thread
thread tid: 139921738565376
task tid: 139921831233280
Results: [42, 'Finished']
```
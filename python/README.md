This directory contains various examples written in Python language

Some of them require python at least 3.6 version. For easy python version managing use pyenv scripts that could be set up in steps as follow:
1. [Installer instruction](https://github.com/pyenv/pyenv-installer)
2. pyenv install 3.6.3
3. pyenv virtualenv 3.6.3 test_environment
4. pyenv activate test_environment


* [async](async/)

asyncio examples directory.

* [decorator.py](./decorator.py)

```
original function 12
Simple decorator
original function 12
decorator with params ('This is decorator param',)
original function 12
Class Decorator
original function 12
ClassDecoratorParams ('decorator params',)
original function 12
```

* [fib_generator.py](./fib_generator.py)


Generate fibonacci sequence with generator function
```
1 1 2 3 5 8 13 21 34 55 
[1, 1, 2, 3, 5, 8, 13, 21, 34, 55]
```

* [index.py](./index.py)

Usage of python __index__ special method

```
a is [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
First 2 a' elements: [0, 1]
[0, 2, 4, 6, 8]
```
* [thread_multiprocess.py](./thread_multiprocess.py)

Shows difference between python Thread and Process classes.

```output
spawn thread
process spawned
value is 2
value changed to 53
value is 53
spawn process
process spawned
value is 2
value is 2
value changed to 53
```
* [coroutine.py](./coroutine.py)

Example of sending data to coroutine and getting value out of it.
```

yield generator object test
first line
second line
Bingo
Result is 12
Stop Iteration
async coroutine object test
coroutine returned: Hello im coroutine
```

* [log.py](./log.py)

Python built in logger example
```
DEBUG:root:Debug message
INFO:root:Info message
WARNING:root:Warn message
ERROR:root:Error message
CRITICAL:root:Critical message
fileLogger: Info message
fileLogger: Warn message
fileLogger: Error message
fileLogger: Critical message
	Default logger
	defaultToFile
```
* [else.py](./else.py)

Demonstrate exotic else keyword usage in for loop and try statement
```
hi
Random number not found
except block
finally block
```

* [attrs_test.py](./attrs_test.py)

Create simple classes with attr module
```
Attribute(name='a', default=NOTHING, validator=<function SomeClass.check at 0x7fe09500e7b8>, repr=True, cmp=True, hash=None, init=True, metadata=mappingproxy({}), type=None, converter=None, kw_only=False) = 1
Hi
SomeClass(a=1, ss='Hi')
{'a': 1, 'ss': 'Hi'}
```

* [crypto.py](./crypto.py)

Generationg and serialization EC keypair with python cryptography module
```
Hi
b'-----BEGIN EC PRIVATE KEY-----\nMIGkAgEBBDChBsHfs7vccT8JtWBUy39nvXRebhqxqh9FsnFQguwZIk5eEZeeDzCh\n1I8Ga0LeU0GgBwYFK4EEACKhZANiAAQLMmst5YwVxBp3Ijan1LcBQUq9j3YY/5ni\nC8FRYZzoXAk5VPCdWfVB0zJk3D4Dgp1xjwgyNwPoqRNj1uPZG9ArokIdvmLrrk8f\nAOnDMJTwhjxlxFPXpnFkQ+EhUXIa7n8=\n-----END EC PRIVATE KEY-----\n'
b'-----BEGIN PUBLIC KEY-----\nMHYwEAYHKoZIzj0CAQYFK4EEACIDYgAECzJrLeWMFcQadyI2p9S3AUFKvY92GP+Z\n4gvBUWGc6FwJOVTwnVn1QdMyZNw+A4KdcY8IMjcD6KkTY9bj2RvQK6JCHb5i665P\nHwDpwzCU8IY8ZcRT16ZxZEPhIVFyGu5/\n-----END PUBLIC KEY-----\n'
```

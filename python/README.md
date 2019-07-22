This directory contains various examples written in Python language

Some of them require python at least 3.6 version. For easy python version managing use pyenv scripts that could be set up in steps as follow:
1. [Installer instruction](https://github.com/pyenv/pyenv-installer)
2. pyenv install 3.6.3
3. pyenv virtualenv 3.6.3 test_environment
4. pyenv activate test_environment


[async](async/)
Directory with asyncio examples

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

#!/usr/bin/env python3

def original_func(arg: int):
    print(f"original function {arg}")

def simple_decorator(f):
    def wrapper(*args):
        print("Simple decorator")
        f(*args)
    return wrapper

@simple_decorator
def original_func_dec(*arg):
    original_func(*arg)

def decorator_param(*param):
    def deco(f):
        def wrapper(*args):
            print(f"decorator with params {param}")
            f(*args)
        return wrapper
    return deco

@decorator_param("This is decorator param")
def original_func_dec_param(*arg):
    original_func(*arg)

class ClassDecorator:
    def __init__(self, f):
        self.f = f
    def __call__(self, *arg):
        print("Class Decorator")
        self.f(*arg)

@ClassDecorator
def original_func_class_dec(*arg):
    original_func(*arg)

class ClassDecoratorParams:
    def __init__(self, *params):
        self.params = params

    def __call__(self, f):
        def wrapper(*args):
            print(f"ClassDecoratorParams {self.params}")
            f(*args)
        return wrapper

@ClassDecoratorParams("decorator params")
def original_func_class_dec_params(*arg):
    original_func(*arg)

original_func(12)
original_func_dec(12)
original_func_dec_param(12)
original_func_class_dec(12)
original_func_class_dec_params(12)

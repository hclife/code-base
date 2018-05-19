#!/usr/bin/env python3
x=50
def func():
    global x
    print('x is',x)
    x=2
    print('Global x is changed to',x)
func()
print('Value of x is',x)

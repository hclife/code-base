#!/usr/bin/env python3
x=50
def func(x):
    print('x is',x)
    x=2
    print('Local x is changed to',x)
func(x)
print('x is still',x)

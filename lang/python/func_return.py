#!/usr/bin/env python3
def maximum(x,y):
    if x>y:
        return x
    elif x<y:
        return y
    else:
        return 'The numbers are equal.'

def maximum1(x,y):
    if x>y:
        return x
    if x<y:
        return y
    return 'The two numbers are equal.'

print(maximum(2,3))
print(maximum1(8,8))

#!/usr/bin/env python3
def print_max(x,y):
    '''Print the maximal value of two numbers.

    These two numbers both should be integers.'''
    x=int(x)
    y=int(y)
    if x>y:
        print(x,'is maximum val')
    else:
        print(y,'is maximum val')

def my_func():
    """Do nothing, but document it.

    No, really, it doesn't do anything.
    """

print_max(3,5)
print(print_max.__doc__)
print(my_func.__doc__)
#help(print_max)

#!/usr/bin/env python

def display_name_type(num):
    print num, 'is',
    if isinstance(num, (int, long, float, complex)):
        print 'a number of type:', type(num).__name__
    else:
        print 'not a number at all!!!'

display_name_type(-69)
display_name_type(99999999999999999999L)
display_name_type(98.6)
display_name_type(-5.2+1.9j)
display_name_type('xxx')

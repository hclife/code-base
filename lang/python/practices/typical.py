#!/usr/bin/env python

"""This is a test module"""

import sys
import os

debug = True

class FOO(object):
    'Foo class'
    pass

def test():
    """test function"""
    foo = FOO()
    if debug:
        print 'ran test()'

if __name__ == '__main__':
    test()
    

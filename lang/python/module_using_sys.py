#!/usr/bin/env python3
import sys
import os

print('The command line arguments are:')
for i in sys.argv:
    print(i)
print('\n\nThe PYTHONPATH is',sys.path,'\n')
print('\n\nThe current work dir is',os.getcwd(),'\n')

from math import sqrt
print("Square root of 16 is",sqrt(16))

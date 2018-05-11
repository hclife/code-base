#!/usr/bin/python

import sys

while True:
    x = raw_input("Please input the operation number: ")
    if (x == 'X' or x == 'x'):
        print 'Exit'
        sys.exit()
    elif (int(x) == 1):
        print 'Get the sum of five numbers'
    elif (int(x) == 2):
        print 'Get the average of five numbers'
    else:
        print 'Please input again'
        pass


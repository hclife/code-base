#!/usr/bin/env python

""" TextFile.py -- create and display text file """

import os
import sys
ls = os.linesep

def create():
    fname = raw_input('Enter file to edit > ')
    if os.path.exists(fname):
        fobj = open(fname, 'a')
    else:
        fobj = open(fname, 'w')

    # get file content (text) lines
    all = []
    print "\nEnter lines ('.' by itself to quit).\n"

    # loop until user terminates input
    while True:
        entry = raw_input('Input lines > ')
        if entry == '.':
            break
        else:
            all.append(entry)

    # write lines to file with proper line-ending
    fobj.writelines(['%s%s' % (x, ls) for x in all])
    fobj.close()
    print 'DONE!'

def display():
    # get filename
    fname = raw_input('Enter filename: ')
    print

    # attempt to open file for reading
    if os.path.exists(fname):
        # display the contents to screen
        fobj = open(fname, 'r')
        for line in fobj:
            print line,
        fobj.close()
    else:
        print "ERROR: '%s' doesn't exist" % fname

if __name__ == "__main__":
    print 'main enter'
    x = int(input("Please input mode (1:create 2:display) > "))
    if (x == 1):
        create()
    elif (x == 2):
        display()
    else:
        print 'unknown mode'

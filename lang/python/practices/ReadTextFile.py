#!/usr/bin/env python

"""ReadTextFile.py -- read and display text file"""

# get filename
fname = raw_input('Enter filename: ')
print

# attemp to open file for reading
try:
    fobj = open(fname, 'r')
except IOError, e:
    print "*** file open error:", e
else:
    # display the contents to screen
    for line in fobj:
        print line.strip()
    fobj.close()

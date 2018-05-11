#!/usr/bin/env python

"""ReadTextFile.py -- read and display text file"""

import os

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

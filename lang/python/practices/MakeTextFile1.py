#!/usr/bin/env python

""" MakeTextFile.py -- create text file """

import os
ls = os.linesep

# get filename
while True:
    fname = raw_input('Input file name > ')
    try:
        fobj = open(fname, 'r')
    except IOError, e:
        #print "*** file open error:", e
        break
    else:
        print "This file '%s' already exists" % fname
        fobj.close()
        pass

# get file content (text) lines
all = []
print "\nEnter lines ('.' by itself to quit).\n"

# loop until user terminates input
while True:
    entry = raw_input('Input file lines > ')
    if entry == '.':
        break;
    else:
        all.append(entry)

# write lines to file with proper line-ending
fobj = open(fname, 'w')
fobj.writelines(['%s%s' % (x, ls) for x in all])
fobj.close()
print 'DONE!'

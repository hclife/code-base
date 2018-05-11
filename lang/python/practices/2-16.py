#!/usr/bin/python

filename = raw_input('Enter a file name: ')
fobj = open(filename, 'r')
for each_line in fobj:
    print each_line
fobj.close()

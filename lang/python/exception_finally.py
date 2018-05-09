#!/usr/bin/env python3
import sys
import time

f=None
try:
    f=open("poem.txt")
    while True:
        line=f.readline()
        if len(line)==0:
            break
        print(line,end='')
        sys.stdout.flush()
        #print("Press ctrl+c now...")
        time.sleep(1)
except IOError:
    print("Couldn't find file poem.txt!")
except KeyboardInterrupt:
    print("The reading on file poem.txt is aborted!")
finally:
    if f: f.close()
    print("(Clearning up: Closed the file.)")

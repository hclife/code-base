#!/usr/bin/env python3
poem='''Programming is fun
When the work is done
If you wanna make your work also fun:
    Use Python!
'''

f=open('poem.txt','w')
f.write(poem)
f.close()

# default set to read mode if not specified
f=open('poem.txt')
while True:
    line=f.readline()
    if len(line)==0:
        break
    print(line,end='')
f.close()

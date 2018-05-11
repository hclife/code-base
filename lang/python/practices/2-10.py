#!/usr/bin/python
while True:
    x=int(input("Please input a number (1~100): "))
    if (x < 1 or x > 100):
        print 'Input %d wrong, please input again.' % x
    else:
        print x
        break
    

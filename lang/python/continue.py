#!/usr/bin/env python3
while True:
    s=input('Enter something: ')
    if s=='quit':
        break
    if len(s)<3:
        print('Too small')
        continue
    print('Input has sufficient length')

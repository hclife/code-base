#!/usr/bin/env python3
def func(a,b=5,c=10):
    print('a is',a,'and b is',b,'and c is',c)
func(3,7)           # a=3,b=7,c=10
func(25,c=24)       # a=25,b=5,c=24
func(c=50,a=100)    # a=100,b=5,c=50

def parrot(voltage,state='a stiff',action='voom',
           type='Norwegian Blue'):
    print("-- This parrot wouldn't",action,end='')
    print(", if you put",voltage,"volts through it.")
    print("-- Lovely plumage, the",type)
    print("-- It's",state,"!")
parrot(1000)
parrot(voltage=1000)
parrot(voltage=1e6,action='VOOOOOM')
parrot(action='VOOOOOM',voltage=1e6)
parrot('a million','bereft of life','jump')
parrot('a thousand',state='pushing up the daisies')

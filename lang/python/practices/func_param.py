#!/usr/bin/env python3
def print_max(a,b):
    if a>b:
        print(a,'is maximum')
    elif a<b:
        print(b,'is maximum')
    else:
        print(a,'is equal to',b)
print_max(3,4)
x=5
y=7
print_max(x,y)

def write_multiple_items(file,separator,*args):
    file.write(separator.join(args))

def concat(*args,sep="/"):
    return sep.join(args)
print(concat("earth","mars","venus"))
print(concat("earth","mars","venus",sep=","))

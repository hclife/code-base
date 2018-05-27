#!/usr/bin/env python3
points=[{'x':2,'y':3},
        {'x':4,'y':1}]
points.sort(key=lambda i:i['y'])
print(points)

def make_incrementor(n):
    return lambda x:x+n
f=make_incrementor(42)
print(f(0))
print(f(1))

pairs=[(1,'one'),(2,'two'),(3,'three'),(4,'four')]
pairs.sort(key=lambda pair:pair[1])
print(pairs)

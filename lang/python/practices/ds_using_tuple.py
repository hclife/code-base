#!/usr/bin/env python3
zoo=('python','elephant','penguin')
print('Number of animals in zoo is',len(zoo))

new_zoo='monkey','camel',zoo
print('Number of cages in new zoo is',len(new_zoo))
print('All animals in new zoo are',new_zoo)
print('Animals brought from old zoo are',new_zoo[2])
print('Last animal brought from old zoo is',new_zoo[2][2])
print('Number of animals in new zoo is',len(new_zoo)-1+len(new_zoo[2]))

empty=()
print(empty)
print(len(empty))
singleton='hello',
print(singleton)
print(len(singleton))
t=123,321,'hello' # tuple packing
print(t)
x,y,z=t # sequence unpacking
print('x =',x,'y =',y,'z =',z)

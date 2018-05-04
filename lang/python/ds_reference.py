#!/usr/bin/env python3
print('Simple Assignment')
shoplist=['apple','mango','carrot','banana']
mylist=shoplist
del shoplist[0]
print('shoplist:',shoplist)
print('mylist:',mylist)

print('copy by making a full slice')
mylist=shoplist[:]
del mylist[0]
print('shoplist:',shoplist)
print('mylist:',mylist)

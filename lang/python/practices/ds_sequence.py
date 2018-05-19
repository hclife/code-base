#!/usr/bin/env python3
shoplist=['apple','mango','carrot','banana']
name='swaroop'

# indexing / subscription operations
print('item[0]=',shoplist[0])   # apple
print('item[1]=',shoplist[1])   # mango
print('item[2]=',shoplist[2])   # carrot
print('item[3]=',shoplist[3])   # banana
print('item[-1]=',shoplist[-1]) # banana
print('item[-2]=',shoplist[-2]) # carrot
print('step(1)=',shoplist[::1])
print('step(2)=',shoplist[::2]) # apple,carrot
print('step(3)=',shoplist[::3]) # apple,banana
print('step(-1)=',shoplist[::-1])
print('character[0]=',name[0])  # s

# slicing operations on the list
print('item[1-3]=',shoplist[1:3])   # mango,carrot
print('item[2-E]=',shoplist[2:])    # carrot,banana
print('item[1--1]=',shoplist[1:-1]) # mango,carrot
print('item[S-E]=',shoplist[:])     # apple,mango,carrot,banana

# slicing operations on the string
print('character[1-3]=',name[1:3])  # wa
print('character[2-E]=',name[2:])   # aroop
print('character[1--1]=',name[1:-1])# waroo
print('character[S-E]=',name[:])    # swaroop

#!/usr/bin/env python3
# list comprehensions

listone=[2,3,4]
listtwo=[2*i for i in listone if i>2]
print(listtwo)

ssize=[]
for x in range(10): ssize.append(x**2)
#ssize=list(map(lambda x: x**2, range(10)))
#ssize=[x**2 for x in range(10)]
print(ssize)

tsize=[(x,y) for x in [1,2,3]
             for y in [3,1,4] if x!=y]
print(tsize)

combs=[]
for x in [1,2,3]:
    for y in [3,1,4]:
        if x!=y: combs.append((x,y))
print(combs)

vec=[-4,-2,0,2,4]
print(vec)
vec1=[x*2 for x in vec]
print(vec1)
vec2=[x for x in vec if x>=0]
print(vec2)
vec3=[abs(x) for x in vec]
print(vec3)

freshfruit=['  banana',' loganberry',' passion fruit ']
print(freshfruit)
fruit1=[weapon.strip() for weapon in freshfruit]
print(fruit1)

dlist=[(x,x**2) for x in range(6)]
print(dlist)

vec2d=[[1,2,3],[4,5,6],[7,8,9]]
vec2f=[num for elem in vec2d for num in elem]
print(vec2f)

from math import pi
vexp=[str(round(pi,i)) for i in range(1,6)]
print(vexp)

matrix=[
    [1,2,3,4],
    [5,6,7,8],
    [9,10,11,12],
]
print(matrix)

# transpose = transpose1 = transpose2
transpose=[[row[i] for row in matrix] for i in range(4)]
print(transpose)
transpose1=[]
for i in range(4):
    transpose1.append([row[i] for row in matrix])
print(transpose1)
transpose2=[]
for i in range(4):
    transpose2_row=[]
    for row in matrix:
        transpose2_row.append(row[i])
    transpose2.append(transpose2_row)
print(transpose2)
print(list(zip(*matrix)))

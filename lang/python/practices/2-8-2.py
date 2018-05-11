#!/usr/bin/python
a=[]
i = 0
while i < 5:
    x = int(input("Please enter a num: "))
    a.append(x)
    i += 1
sum = 0
for x in a:
    sum += x
print sum

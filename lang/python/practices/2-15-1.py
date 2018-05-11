#!/usr/bin/python

import sys

x = int(input("Enter the first number: "))
y = int(input("Enter the second number: "))
z = int(input("Enter the third number: "))

if (x > y):
    x,y = y,x
if (x > z):
    x,z = z,x
if (y > z):
    y,z = z,y
print x,y,z


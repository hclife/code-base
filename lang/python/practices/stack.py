#!/usr/bin/env python3

stack=[3,4,5]

stack.append(6)
stack.append(7)
print(stack) #3,4,5,6,7

stack.pop()
print(stack) #3,4,5,6

stack.pop()
stack.pop()
print(stack) #3,4

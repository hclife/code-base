#!/usr/bin/env python3

def say(message,times=1):
    print(message*times)
say('Hello')
say('World',5)


# important warning: The default value of function parameters
# is evaluated only once at the point of function definition.
def fun(a,L=[]):
    L.append(a)
    return L
print(fun(1)) # [1]
print(fun(2)) # [1,2]
print(fun(3)) # [1,2,3]

def fan(a,L=None):
    if L is None: L=[]
    L.append(a)
    return L
print(fan(1)) # [1]
print(fan(2)) # [2]
print(fan(3)) # [3]


def ask_ok(prompt,retry=4,reminder='Please try again!'):
    while True:
        ok=input(prompt)
        if ok in ('y','ye','yes'):
            return True
        if ok in ('n','no','nop','nope'):
            return False
        retry-=1
        if retry<0:
            raise ValueError('Invalid User Response!')
        print(reminder)
ask_ok('Do you really wanna quit?')
ask_ok('Is that ok to overwrite file?')
ask_ok('Is that ok to overwrite file?',2)
ask_ok('Is that ok to overwrite file?',2,
       'Come on, input only yes or no!')

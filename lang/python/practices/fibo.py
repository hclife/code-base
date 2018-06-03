#!/usr/bin/python
#Fibonacci numbers module

def fib1(n):
    '''Print a Fibonacci series up to n.'''
    a,b=0,1
    while b<n:
        print(b,end=' ')
        a,b=b,a+b
    print('')

def fib2(n):
    '''List with a Fibonacci series up to n.'''
    result=[]
    a,b=0,1
    while b<n:
        result.append(b)
        a,b=b,a+b
    return result

if __name__ == "__main__":
    import sys
    fib1(10)
    res=fib2(10)
    print(res)

#!/usr/bin/env python3

def divide(x,y):
    try: result=x/y
    except ZeroDivisionError:
        print('Division by zero!')
    else:
        print('Result is',result)
    finally:
        print('Executing finally!')

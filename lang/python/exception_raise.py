#!/usr/bin/env python3
# encoding=UTF-8
class ShortInputException(Exception):
    '''An exception class defined by user.'''
    def __init__(self,length,least):
        Exception.__init__(self)
        self.length=length
        self.least=least

try:
    text=input('Enter something => ')
    if len(text)<3:
        raise ShortInputException(len(text),3)
    # The other works can run here normally
except EOFError:
    print('Why did you do an EOF on me?')
except KeyboardInterrupt:
    print('The operation is cancelled.')
except ShortInputException as ex:
    print(('ShortInputException: The input was '+
           '{0} long, excepted at least {1}.')
           .format(ex.length,ex.least))
else:
    print('No exception was raised.')
    print("You've entered {}".format(text))


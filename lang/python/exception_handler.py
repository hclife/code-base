#!/usr/bin/env python3
try:
    text=input('Enter something => ')
except EOFError:
    print('Why did you do an EOF on me?')
except KeyboardInterrupt:
    print('The operation is cancelled.')
else:
    print("You've entered {}".format(text))

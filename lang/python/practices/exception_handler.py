#!/usr/bin/env python3
try:
    text=input('Enter something => ')
except EOFError:
    print('Why did you do an EOF on me?')
except KeyboardInterrupt:
    print('The operation is cancelled.')
except ValueError:
    print('Oops! That was no valid number. Try Again!')
else:
    print("You've entered {}".format(text))

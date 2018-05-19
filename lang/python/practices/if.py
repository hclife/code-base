#!/usr/bin/env python3
flag=True
# Be careful for single suite
if flag: print('Yes')

number=24
guess=int(input('Enter an integer : '))
if guess==number:
    print('Congratulations, you guessed it.')
    print('(but you do not win any prizes!)')
elif guess<number:
    print('No, it is a little higher than that')
else:
    print('No, it is a little lower than that')
print('Done')


#!/usr/bin/env python3
number=24
running=True
while running:
    guess=int(input('Enter an integer : '))
    if guess==number:
        print('Congratulations, you guessed it.')
        print('(but you do not win any prizes!)')
        running=False
    elif guess<number:
        print('No, it is a little higher than that')
    else:
        print('No, it is a little lower than that')
else:
    print('The while loop is over.')
print('Done')

#!/usr/bin/env python3
age=20
name='Swaroop'
print('{0} was {1} years old when he wrote this book'.format(name,age))
print('Why is {0} playing with that python?'.format(name))
print('{} was {} years old when second way'.format(name,age))
print('Why is {} playing with that second python?'.format(name))
print('{0:.3f}'.format(1.0/3))
print('{0:_^11}'.format('hello'))
print('{name} wrote {book}'.format(name='Skove',book='Byte of Python'))
print('{} and {}'.format('spam','eggs'))
print('{0} and {1}'.format('spam','eggs'))
print('{1} and {0}'.format('spam','eggs'))
print('This {food} is {adjective}.'.format(food='spam',
      adjective='absolutely horrible'))
print('The story of {0}, {1} and {other}.'.format('Bill',
      'Manfred',other='George'))
table={'Sjoerd':4127,'Jack':4098,'Dcab':8637}
print('Jack: {0[Jack]:d}, Sjoerd: {0[Sjoerd]:d},'
      'Dcab: {0[Dcab]:d}'.format(table))

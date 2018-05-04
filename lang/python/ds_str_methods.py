#!/usr/bin/env python3
name='swaroop'
if name.startswith('swa'):
    print('Yes, the string starts with "swa"')
if 'a' in name:
    print('Yes, the string contains str "a"')
if name.find('war')!=-1:
    print('Yes, the string contains str "war"')

delimiter='_*_'
mylist=['brazil','russia','india','china']
print(delimiter.join(mylist))

#!/usr/bin/env python3

basket={'apple','orange','apple','pear','orange','banana'}
print('basket:',basket)
print('orange' in basket)
print('crabgrass' in basket)

a=set('abracadabra')
b=set('alacazam')
c={x for x in 'abracadabra' if x not in 'abc'}
print('a:',a)
print('b:',b)
print('c:',c)
print('a-b:',a-b)
print('a|b:',a|b)
print('a&b:',a&b)
print('a^b:',a^b)

#!/usr/bin/env python3

# +---+---+---+---+---+---+
# | P | y | t | h | o | n |
# +---+---+---+---+---+---+
# 0   1   2   3   4   5   6
#-6  -5  -4  -3  -2  -1

word='python'

# string indexing / subscription operations
list_index=[0,5,-1,-2,-6]
for x in list_index:
    print(word[x],end=' ')
print('')

# string slicing operations
print(word[0:2])
print(word[2:5])
print(word[:2])
print(word[4:])
print(word[-2:])
# s=s[:i]+s[i:]
print(word[:2]+word[2:])
print(word[:4]+word[4:])
print(word[4:42])
print(word[42:])
print('j'+word[1:])
print(word[:2]+'py')

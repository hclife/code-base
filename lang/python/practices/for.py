#!/usr/bin/env python3

print(range(10))      # range() returns an iterable object
print(list(range(5))) # list() create lists from iterables

#for i in range(5,10):
#for i in range(1,10,2):
#for i in range(0,10,3):
for i in range(-10,-100,-30):
#for i in range(10):
    print(i,end=' ')
else:
    print('\nThe for loop is over.\n')

# measure some strings
words=['cat','window','defenestrate']
for w in words:
    print(w,len(w))

# loop over a slice copy of the entire list
for w in words[:]:
    if len(w)>6:
        words.insert(0,w)
print(words,end='\n\n')

story=['Mary','had','a','little','lamb']
for i in range(len(story)):
    print(i,story[i])
print('')

# search for prime numbers
for n in range(2,10):
    for x in range(2,n):
        if n%x==0:
            print(n,'=',x,'*',n//x)
            break
    else:
        # loop fell through without finding a factor
        print(n,'is a prime number')
print('')

# search the even numbers
for num in range(2,10):
    if num%2==0:
        print('Found an even number',num)
        continue
    print('Found a odd number',num)

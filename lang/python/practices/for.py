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

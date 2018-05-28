#!/usr/bin/env python3

# This is my shopping list
shoplist=['apple','mango','carrot','banana']
print('I have',len(shoplist),'items to purchase.')
print('These items are:',end=' ')
for item in shoplist:
    print(item,end=' ')

print('\nI also have to buy rice.')
shoplist.append('rice')
print('My shopping list is now',shoplist)

print('I will sort my list now')
shoplist.sort()
print('The sorted shopping list is',shoplist)

print('The first item I will buy is',shoplist[0])
olditem=shoplist[0]
del shoplist[0]
print('I have bought the',olditem)
print('My shopping list is now',shoplist)

print('-'*64)
# This is my fruits list
fruits=['orange','apple','pear','banana',
        'kiwi','apple','banana']
print('count(apple)=',fruits.count('apple'))
print('count(tangerine)=',fruits.count('tangerine'))
print('index(banana)=',fruits.index('banana'))
print('index(banana,4)=',fruits.index('banana',4))
fruits.reverse();print(fruits)
fruits.append('grape');print(fruits);
fruits.sort();print(fruits)
fruits.pop();print(fruits)

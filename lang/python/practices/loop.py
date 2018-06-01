#!/usr/bin/env python3

knights={'gallahad':'the pure','robin':'the brave'}
for k,v in knights.items(): print(k,v)
for i,v in enumerate(['tic','tac','toc']): print(i,v)

questions=['name','quest','favorite color']
answers=['Lancelot','the holy grail','blue']
for q,a in zip(questions,answers):
    print('What is your {0}? It is {1}.'.format(q,a))

for i in reversed(range(1,10,2)): print(i,end=' ')
print('')

basket=['apple','orange','apple','pear','orange','banana']
for b in sorted(set(basket)): print(b)

s1,s2,s3='','Trondheim','Hammer Dance'
non_null=s1 or s2 or s3
print('non_null:',non_null)

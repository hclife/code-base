#!/usr/bin/env python3
data=set(['brazil','russia','india'])

if 'india' in data:
    print('india is in data')
else:
    print('india is not in data')

if 'usa' in data:
    print('usa is in data')
else:
    print('usa is not in data')

datas=data.copy()
datas.add('china')
x=datas.issuperset(data)
print('datas supersets data =',x)
print('data :',data)
print('datas:',datas)
data.remove('russia')
print('AND:',data & datas)
print('AND:',data.intersection(datas))
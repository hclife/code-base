#!/usr/bin/env python3

tel={'jack':4098,'sape':4139}
tel['guido']=4127
print('tel=',tel)
print('tel[jack]=',tel['jack'])
del tel['sape']
tel['vir']=4127
print('tel=',tel)
print(list(tel.keys()))
print(sorted(tel.keys()))
print('guido' in tel)
print('jack' not in tel)

_tel=dict([('sape',4139),
           ('guido',4127),
           ('jack',4098)])
print('_tel=',_tel)

__tel=dict(sape=4139,guido=4127,jack=4098)
print('__tel=',__tel)

dx={x: x**2 for x in (2,4,6)}
print('dx=',dx)


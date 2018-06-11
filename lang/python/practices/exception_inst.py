#!/usr/bin/env python3

try:
    raise Exception('spam','eggs')
except Exception as inst:
    print('type(inst) =',type(inst))
    print('inst.args =',inst.args)
    print('inst =',inst)
    x,y=inst.args #unpack arguments
    print('x = {0}, y = {1}'.format(x,y))

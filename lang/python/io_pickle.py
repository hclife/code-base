#!/usr/bin/env python3
# Standard MODULE pickle is used to save any pure
# python object into a file, and then retrieve it
# lately, which means saving object persistently.
import pickle
shoplistfile='shoplist.data'
shoplist=['apple','mango','carrot']
fp=open(shoplistfile,'wb')
pickle.dump(shoplist,fp)
fp.close()

# Eliminate the shoplist
del shoplist

fp=open(shoplistfile,'rb')
storelist=pickle.load(fp)
print(storelist)


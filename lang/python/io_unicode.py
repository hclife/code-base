#!/usr/bin/env python3
#encoding=utf-8
import io

f=io.open("abc.txt","wt",encoding="utf-8")
f.write(u"Imagine non-English language here.上帝")
f.close()

f=io.open("abc.txt",encoding="utf-8")
text=f.read()
print(text)
f.close()


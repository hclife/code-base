#!/usr/bin/env python3

import fibo
import fibo as fib
from fibo import fib1,fib2
from fibo import *
from fibo import fib1 as fibonacci

import importlib
importlib.reload(fibo)

# The Fibonacci series calculation:
a,b=0,1
while b<10:
    print(b,end=' ')
    a,b=b,a+b
print('')

# import sound.effects.echo
# import sound.effects.surround
# from sound.effects import echo
# from sound.effects import *
# from sound.effects.echo import echofilter
# from . import echo
# from .. import formats
# from ..filters import equalzer

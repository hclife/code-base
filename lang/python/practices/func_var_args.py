#!/usr/bin/env python3
def total(a=5,*numbers,**phonebook):
    print('a',a)
    for single_item in numbers:
        print('single_item',single_item)
    for first_part,second_part in phonebook.items():
        print(first_part,second_part)
print(total(10,1,2,3,Jack=1123,John=2231,Inge=1560))
print("")

def cheese_shop(kind,*arguments,**keywords):
    print("-- Do you have any",kind,"?")
    print("-- I'm sorry, we're all out of",kind,".")
    for arg in arguments:
        print(arg)
    print("-"*40)
    for key in keywords:
        print(key,":",keywords[key])
cheese_shop("Limburger","It's very runny, sir.",
            "It's really very VERY runny, sir.",
            shopkeeper="Michael Palin",
            client="John Cleese",
            sketch="Cheese Shop Sketch")

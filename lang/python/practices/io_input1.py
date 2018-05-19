#!/usr/bin/env python3

def change(data):
    text=[]
    for x in data:
        if x.isalpha():
            text+=x
    return text

def reverse(text):
    return text[::-1]

def is_palindrome(text):
    return text==reverse(text)

while True:
    data=input('Enter text:')
    if len(data)==0:
        break
    text=change(data)
    text=''.join(text)
    if is_palindrome(text.lower()):
        print('Yes, it is a palindrome')
    else:
        print('No, it is not a palindrom')

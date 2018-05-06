#!/usr/bin/env python3
def reverse(text):
    return text[::-1]
def is_palindrome(text):
    return text==reverse(text)
data=input('Enter text:')
if is_palindrome(data):
    print('Yes, it is a palindrome')
else:
    print('No, it is not a palindrom')

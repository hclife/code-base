#!/usr/bin/python

class Foo(object):
    """my very first class"""
    version=0.1
    def __init__(self, nm='John Doe'):
        """constructor"""
        self.name=nm
        print 'Created a class instance for', nm
    def show_name(self):
        """display instance attribute and class name"""
        print 'Your name is', self.name
        print 'My name is', self.__class__.__name__
    def show_ver(self):
        """display class(static) attribute"""
        print self.version
    def add_meme(self,x):
        """apply + operation to argument"""
        return x+x

if __name__ == "__main__":
    import sys

#!/usr/bin/env python3
class Robot:
    '''Robot class means an android with a name.'''
    population=0
    def __init__(self,name):
        '''Initialize robot data.'''
        self.name=name
        print('(Initializing {})'.format(self.name))
        Robot.population+=1
    def die(self):
        '''I am dead.'''
        print('{} is being destroyed!'.format(self.name))
        Robot.population-=1
        if Robot.population==0:
            print('{} was the last one.'.format(self.name))
        else:
            print('There are still {:d} robots working.'.\
                  format(Robot.population))
    def say_hi(self):
        '''Sincere greetings come from Robots.'''
        print('Greetings, my masters call me {}.'.format(self.name))

    @classmethod
    #how_many=classmethod(how_many)
    def how_many(cls):
        '''Print the number of current population'''
        print('We have {:d} robots.'.format(cls.population))

print(Robot.__doc__)
print(Robot.say_hi.__doc__)
print(Robot.die.__doc__)

android1=Robot("R2-D2")
android1.say_hi()
Robot.how_many()

android2=Robot("C-3PO")
android2.say_hi()
Robot.how_many()

print('\nRobots can do some work here...\n')

print("Robots have finished their work. So let's destroy them.")
android1.die()
android2.die()
Robot.how_many()

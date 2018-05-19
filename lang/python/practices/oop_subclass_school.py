#!/usr/bin/env python3
class SchoolMember:
    '''SchoolMember means any member at school'''
    def __init__(self,name,age):
        self.name=name
        self.age=age
        print('(Initialized smember:{})'.format(self.name))
    def tell(self):
        '''Tell details about me'''
        print('Name:"{}" Age:"{}"'.format(self.name,self.age),end=' ')

class Teacher(SchoolMember):
    '''This means a teacher'''
    def __init__(self,name,age,salary):
        SchoolMember.__init__(self,name,age)
        self.salary=salary
        print('(Initialized teacher:{})'.format(self.name))
    def tell(self):
        print('Teacher',end=' ')
        SchoolMember.tell(self)
        print('Salary:"{:d}"'.format(self.salary))

class Student(SchoolMember):
    '''This means a student'''
    def __init__(self,name,age,marks):
        SchoolMember.__init__(self,name,age)
        self.marks=marks
        print('(Initialized student:{})'.format(self.name))
    def tell(self):
        print('Student',end=' ')
        SchoolMember.tell(self)
        print('Marks:"{:d}"'.format(self.marks))

t=Teacher('Mrs.Shrividya',40,30000)
s=Student('Swaroop',25,75)
print()
members=[t,s]
for mem in members:
    mem.tell()

#!/usr/bin/env python3

# ab: address book
ab={
    'Swaroop':'swaroop@gmail.com',
    'Larry':'larry@wall.org',
    'Matsumoto':'matz@ruby-lang.org',
    'Spammer':'spammer@hotmail.com'
}
print("Swaroop's address is",ab['Swaroop'])
del ab['Spammer']
print('\nThere are {} contacts in address book:'.format(len(ab)))

for name,address in ab.items():
    print('Contact {} at {}'.format(name,address))

ab['Guido']='guido@python.org'
if 'Guido' in ab:
    print("\nGuido's address is",ab['Guido'])

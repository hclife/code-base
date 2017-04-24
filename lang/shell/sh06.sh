#!/bin/bash
# Program:
# 	This program shows the user's choise
# History:
# 2011/05/22	Larkin	First Release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

read -p "Please input (Y/N):" yn
[ "$yn" == "Y" -o "$yn" == "y" ] && echo "OK, continue." && exit 0
[ "$yn" == "N" -o "$yn" == "n" ] && echo "Oh, interrupt." && exit 0
echo "I don't know what your choice is." && exit 0


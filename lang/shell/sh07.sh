#!/bin/bash
# Program:
#	Program shows the script name and parameters...
# History:
# 2011/05/22	Larkin		First release
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

echo "The script name is    ==> $0"
echo "Total parameter number is  ==> $#"
[ "$#" -lt 2 ] && echo "The number of parameter is less than 2. Stop here."\
&& exit 0
echo "Your whole parameters are  ==> '$@'"
echo "The 1st parameter  ==> $1"
echo "The 2nd parameter  ==> $2"

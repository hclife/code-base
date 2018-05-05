#!/usr/bin/env python3
import os
import time

source=['/home/larkin/temp']
target='/home/larkin/backup'
if not os.path.exists(target):
    os.mkdir(target)
    print('Successfully created target directory',target)
today=target+os.sep+time.strftime('%Y%m%d')
now=time.strftime('%H%M%S')
target_zip=today+os.sep+now+'.zip'
if not os.path.exists(today):
    os.mkdir(today)
    print('Successfully created todays directory',today)
zip_cmd='zip -r {0} {1}'.format(target_zip,' '.join(source))

print(zip_cmd)
print('Running:')
if os.system(zip_cmd)==0:
    print('successfully backup to',target_zip)
else:
    print('backup FAILED')

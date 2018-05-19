#!/usr/bin/env python3
import os
import time

source=['/home/larkin/temp']
target='/home/larkin/backup'
target_zip=target+os.sep+time.strftime('%Y%m%d%H%M%S')+'.zip'
if not os.path.exists(target):
    os.mkdir(target)
zip_cmd='zip -r {0} {1}'.format(target_zip,' '.join(source))

print('zip command is:')
print(zip_cmd)
print('Running:')
if os.system(zip_cmd)==0:
    print('successfully backup to',target_zip)
else:
    print('backup FAILED')

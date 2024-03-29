@echo off 
echo Cleaning system rubbish, please wait ... 
del /f /s /q %systemdrive%\*.tmp 
del /f /s /q %systemdrive%\*._mp 
del /f /s /q %systemdrive%\*.log 
del /f /s /q %systemdrive%\*.gid 
del /f /s /q %systemdrive%\*.chk 
del /f /s /q %systemdrive%\*.old 
del /f /s /q %systemdrive%\recycler\*.* 
del /f /s /q %windir%\*.bak 
del /f /s /q %windir%prefetch*.* 
rd /s /q %windir%\temp & md %windir%\temp 
del /f /q %userprofile%\cookies*.* 
del /f /q %userprofile\%recent\*.* 
del /f /s /q "%userprofile%\Local Settings\Temporary Internet Files\*.*"
del /f /s /q "%userprofile%\Local Settings\Temp\*.*"
del /f /s /q "%userprofile%\recent*.*" 
echo Finished cleaning the system junk!
echo. & pause
@echo on

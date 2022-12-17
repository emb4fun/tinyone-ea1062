@echo off

del *.bak /S
cd source
call _clean.bat
cd ..
cd webpage
call _clean.bat
cd ..
cd bootloader
call _clean.bat
cd ..

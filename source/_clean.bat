del *.bak /S
del build\*.* /Q
rmdir "prj\Flash to SDRAM Debug" /S /Q 
rmdir "prj\Flash to SDRAM Release" /S /Q 
rmdir "prj\SDRAM Debug" /S /Q 
rmdir "prj\SDRAM Release" /S /Q 
del prj\*.jlink

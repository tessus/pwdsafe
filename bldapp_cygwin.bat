@echo off
rem  (C) COPYRIGHT International Business Machines Corp. 1996, 2000
rem  All Rights Reserved.
rem
rem  US Government Users Restricted Rights - Use, duplication or
rem  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.

rem bldapp.bat -- Windows 32-bit operating systems
rem Builds a GCC application program under Windows
rem Usage: bldapp prog_name [ db_name [ userid password ]]

rem Set the DB2PATH variable to your DB2 base path, e.g., c:\sqllib
rem Set CYGWIN to your top-level CYGWIN directory.

set DB2PATH=c:\sqllib
set CYGWIN=c:\cygwin

if exist "%1.sqc" goto compile_embedded
goto compile_nonembedded

:compile_embedded
call embprep %1 %2 %3 %4
gcc -c -g -mno-cygwin -I%DB2PATH%\include -I%CYGWIN%\usr\include utilemb.c -o utilemb.o
goto compile

:compile_nonembedded
gcc -c -g -mno-cygwin -I%DB2PATH%\include -I%CYGWIN%\usr\include utilapi.c -o utilapi.o
goto compile

:compile
gcc -c -g -mno-cygwin -I%DB2PATH%\include -I%CYGWIN%\usr\include %1.c -o %1.o

if exist "%1.sqc" goto link_embedded
goto link_nonembedded

:link_embedded
rem gcc -mno-cygwin -target i386-mingw32 -o %1.exe %1.o %DB2PATH%\lib\db2api.lib utilemb.o
gcc %1.o utilemb.o %DB2PATH%\lib\db2api.lib -mno-cygwin -o %1.exe
goto exit

:link_nonembedded
rem gcc -mno-cygwin -target i386-mingw32 -o %1.exe %1.o %DB2PATH%\lib\db2api.lib utilapi.o
gcc -mno-cygwin -o %1.exe %1.o %DB2PATH%\lib\db2api.lib utilapi.o
goto exit

:exit
@echo on

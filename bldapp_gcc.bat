@echo off

rem $Id$

rem  (C) COPYRIGHT International Business Machines Corp. 1996, 2000
rem  All Rights Reserved.
rem
rem  US Government Users Restricted Rights - Use, duplication or
rem  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.

rem bldapp.bat -- Windows 32-bit operating systems
rem Builds a GCC application program under Windows
rem Usage: bldapp prog_name [ db_name [ userid password ]]

rem Set the DB2PATH variable to your DB2 base path, e.g., c:\sqllib
rem Set MINGW to your top-level MINGW directory.
rem Set MINGWDB2 to the directory where you have put the output of 'reimp %DB2PATH%\lib\db2api.lib'.

rem Set MINGW to your top-level MINGW directory.

set DB2PATH=c:\sqllib
set MINGW=c:\mingw
set MINGWDB2=c:\sqllib\mingwdb2api

if exist "%1.sqc" goto compile_embedded
goto compile_nonembedded

:compile_embedded
call embprep %1 %2 %3 %4
gcc -c -DWIN32 -I%DB2PATH%\include -I%MINGW%\include utilemb.c -o utilemb.o
goto compile

:compile_nonembedded
gcc -c -DWIN32 -I%DB2PATH%\include -I%MINGW%\include utilapi.c -o utilapi.o
goto compile

:compile
gcc -c -I%DB2PATH%\include -I%MINGW%\include %1.c -o %1.o

if exist "%1.sqc" goto link_embedded
goto link_nonembedded

:link_embedded
gcc -o %1 %1.o utilemb.o -L%MINGWDB2% -ldb2abind -ldb2agapi -ldb2app -ldb2aprep -ldb2dasapi -ldb2synca -ldb2sys -ldb2util
goto exit

:link_nonembedded
gcc -o %1 %1.o utilapi.o -L%MINGWDB2% -ldb2abind -ldb2agapi -ldb2app -ldb2aprep -ldb2dasapi -ldb2synca -ldb2sys -ldb2util
goto exit

:exit
@echo on

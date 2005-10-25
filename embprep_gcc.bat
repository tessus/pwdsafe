@echo off
rem  (C) COPYRIGHT International Business Machines Corp. 1997, 2000
rem  All Rights Reserved.
rem
rem  US Government Users Restricted Rights - Use, duplication or
rem  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.

rem embprep.bat -- Windows 32-bit operating systems
rem Prep and binds a C/C++ or Micro Focus COBOL embedded SQL program.
rem Usage: embprep <prog_name> [ <db_name> [ <userid> <password> ]]

rem Connect to a database.
if "%1" == "" goto error
if "%2" == "" goto case1
if "%3" == "" goto case2
if "%4" == "" goto error
goto case3
:case1
   db2 connect to sample
   goto prep_step
:case2
   db2 connect to %2
   goto prep_step
:case3
   db2 connect to %2 user %3 using %4

:prep_step
if exist "%1.sqx" goto cpp
if exist "%1.sqb" goto cob
db2 prep %1.sqc bindfile sqlerror continue validate run
if exist "utilemb.sqc" db2 prep utilemb.sqc
goto bind_step
:cpp
db2 prep %1.sqx bindfile
if exist "utilemb.sqx" db2 prep utilemb.sqx
goto bind_step
:cob
db2 prep %1.sqb bindfile

:bind_step
db2 bind %1.bnd blocking all sqlerror continue validate run
db2 connect reset 

goto exit
:error
echo Usage: embprep prog_name [ db_name [ userid password ]]
:exit
@echo on

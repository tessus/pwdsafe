@echo off

rem $Id$

rem BATCH FILE: embprep.bat 
rem Prep and binds a C embedded SQL program on Windows
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
db2 prep %1.sqc bindfile using %1W.bnd package using %1W blocking all sqlerror continue validate run
if exist "utilemb.sqc" db2 prep utilemb.sqc bindfile using utilembW.bnd package using utilembW blocking all
goto bind_step

:bind_step
db2 bind %1%W.bnd blocking all sqlerror continue validate run
db2 bind utilembW.bnd
db2 connect reset 

goto exit
:error
echo Usage: embprep prog_name [ db_name [ userid password ]]
:exit
@echo on

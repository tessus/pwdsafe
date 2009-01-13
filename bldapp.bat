@echo off

rem $Id$

rem Licensed Materials - Property of IBM
rem
rem Governed under the terms of the International
rem License Agreement for Non-Warranted Sample Code.
rem
rem  (C) COPYRIGHT International Business Machines Corp. 1996 - 2002
rem  All Rights Reserved.
rem
rem  US Government Users Restricted Rights - Use, duplication or
rem  disclosure restricted by GSA ADP Schedule Contract with IBM Corp.

rem BATCH FILE: bldapp.bat
rem Builds C applications on Windows
rem Usage: bldapp prog_name [ db_name [ userid password ]]

rem Default compiler is set to Microsoft Visual C++
rem To use a different compiler, comment out 'set BLDCOMP=cl'
rem and uncomment 'set BLDCOMP=icl' or 'set BLDCOMP=ecl'
rem Microsoft C/C++ Compiler
set BLDCOMP=cl

rem Intel C++ Compiler for 32-bit applications
rem set BLDCOMP=icl

rem Intel C++ Compiler for Itanium 64-bit applications
rem set BLDCOMP=ecl

if exist "%1.sqx" goto embedded
if exist "%1.sqc" goto embedded
goto non_embedded

:embedded
rem Precompile and bind the program.
rem Note: some .sqc/.sqx files contain no SQL but link in 
rem utilemb.sqc/.sqx, so if you get this warning, ignore it:
rem SQL0053W  No SQL statements were found in the program.
call embprep %1 %2 %3 %4
rem  Compile the program.
if exist "%1.cxx" goto cpp_emb
%BLDCOMP% /O2 /w -c -DWIN32 %1.c utilemb.c
goto link_embedded
:cpp_emb
%BLDCOMP% -c -DWIN32 %1.cxx utilemb.cxx
rem Link the program.
:link_embedded
link -out:%1.exe %1.obj utilemb.obj db2api.lib
goto exit

:non_embedded
rem  Compile the program.
if exist "%1.cxx" goto cpp_non
%BLDCOMP% -c -DWIN32 %1.c utilapi.c
goto link_non_embedded
:cpp_non
%BLDCOMP% -c -DWIN32 %1.cxx utilapi.cxx
rem Link the program.
:link_non_embedded
link -out:%1.exe %1.obj utilapi.obj db2api.lib
:exit
@echo on

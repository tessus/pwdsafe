-- $Id$

--CONNECT TO <database>;

BIND @pwdsafeL.lst BLOCKING ALL SQLERROR CONTINUE;

GRANT  EXECUTE ON PACKAGE TESSUS.PWDADML TO USER DB2USER;
GRANT  EXECUTE ON PACKAGE TESSUS.PWDINITL TO USER DB2USER;
GRANT  EXECUTE ON PACKAGE TESSUS.PWDSAFEL TO USER DB2USER;

--CONNECT RESET;

--TERMINATE;
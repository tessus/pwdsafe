-- $Id$

--CONNECT TO <database> user <USER>;

BIND @pwdsafe.lst BLOCKING ALL SQLERROR CONTINUE VALIDATE RUN;

--CONNECT RESET;

--TERMINATE;

--<USER> needs SELECT, INSERT, UPDATE on PWDSAFE.PWDLOGIN
--             SELECT, INSERT, UPDATE, DELETE on PWDSAFE.PWDLIST
--             CREATE TABLE and BIND authority
--             CREATE IN schema PWDSAFE
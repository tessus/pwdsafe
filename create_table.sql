-- $Id$

--CONNECT TO <database>;

------------------------------------------------
-- DDL Statements for table "PWDSAFE  "."PWDLOGIN"
------------------------------------------------
 
 CREATE TABLE "PWDSAFE  "."PWDLOGIN"  (
		  "USR" VARCHAR(64) NOT NULL , 
		  "PWD" VARCHAR(80) NOT NULL , 
		  "ADMIN" INTEGER NOT NULL WITH DEFAULT 0 )   
		 IN "DATA4K" INDEX IN "IDX4K" ; 
COMMENT ON TABLE "PWDSAFE  "."PWDLOGIN" IS 'Login Table for Password Application';


-- DDL Statements for primary key on Table "PWDSAFE  "."PWDLOGIN"

ALTER TABLE "PWDSAFE  "."PWDLOGIN" 
	ADD CONSTRAINT "PK_PWDLOGIN" PRIMARY KEY
		("USR");


-- DDL Statements for aliases based on Table "PWDSAFE  "."PWDLOGIN"

CREATE ALIAS "PWDSAFE "."PWDLOGIN" FOR "PWDSAFE  "."PWDLOGIN";


------------------------------------------------
-- DDL Statements for table "PWDSAFE  "."PWDLIST"
------------------------------------------------
 
 CREATE TABLE "PWDSAFE  "."PWDLIST"  (
		  "ACCOUNT" VARCHAR(64) NOT NULL , 
		  "USERID" VARCHAR(64) NOT NULL , 
		  "PASSWORD" VARCHAR(80) FOR BIT DATA , 
		  "DESCRIPTION" VARCHAR(2048) , 
		  "USR" VARCHAR(64) NOT NULL , 
		  "TS" TIMESTAMP )   
		 IN "DATA4K" INDEX IN "IDX4K" ; 
COMMENT ON TABLE "PWDSAFE  "."PWDLIST" IS 'Pwd Table for Password Application';


-- DDL Statements for primary key on Table "PWDSAFE  "."PWDLIST"

ALTER TABLE "PWDSAFE  "."PWDLIST" 
	ADD CONSTRAINT "PK_PWDLIST" PRIMARY KEY
		("ACCOUNT",
		 "USR");


--------------------------------------------
-- Authorization Statements on Tables/Views 
--------------------------------------------

 GRANT DELETE ON TABLE "PWDSAFE  "."PWDLIST" TO USER "DB2USER " ;

 GRANT INSERT ON TABLE "PWDSAFE  "."PWDLIST" TO USER "DB2USER " ;

 GRANT SELECT ON TABLE "PWDSAFE  "."PWDLIST" TO USER "DB2USER " ;

 GRANT UPDATE ON TABLE "PWDSAFE  "."PWDLIST" TO USER "DB2USER " ;
 
 GRANT SELECT ON TABLE "PWDSAFE  "."PWDLOGIN" TO USER "DB2USER " ;

 GRANT UPDATE ON TABLE "PWDSAFE  "."PWDLOGIN" TO USER "DB2USER " ;

COMMIT WORK;

--CONNECT RESET;

--TERMINATE;
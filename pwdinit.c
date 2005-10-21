static char sqla_program_id[162] = 
{
 42,0,65,68,65,75,65,73,80,87,68,73,78,73,84,32,81,66,89,51,
 77,76,67,85,48,49,49,49,49,32,50,32,8,0,65,84,50,52,48,50,
 48,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
 0,0
};

#include "sqladef.h"

static struct sqla_runtime_info sqla_rtinfo = 
{{'S','Q','L','A','R','T','I','N'}, sizeof(wchar_t), 0, {' ',' ',' ',' '}};


#line 1 "pwdinit.sqc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include <conio.h>
#include <ctype.h>
#include "utilemb.h"
#include "php_md5.h"



/*
EXEC SQL INCLUDE SQLCA;
*/

/* SQL Communication Area - SQLCA - structures and constants */
#include "sqlca.h"
struct sqlca sqlca;


#line 11 "pwdinit.sqc"



int execi(char s[1000]);


/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 16 "pwdinit.sqc"

        struct VARCHAR {
           short len;
           char  stmt[1000];
        } sqlstmt; /* Varchar for statement text    */

/*
EXEC SQL END DECLARE SECTION;
*/

#line 21 "pwdinit.sqc"


int main(int argc, char *argv[]) {

   
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 25 "pwdinit.sqc"

           char user[32];           // var for actual user
           char pwd[32];            // host var for hashed pwd in pwdlogin
           char enc_pwd[32];        // pwd entered
           char enc_pwd2[32];       // pwd entered again
           char enc_pwd_final[33];  // md5 hashed pwd

           short admin;				// host var, if user is admin -> allow register new users
           short there;				// host var to check if tables are there
		   char huser[32];
		   char username[32];

           char uid[9];             // connection vars
      	   char passwd[19];
      	   char db[19];
   
/*
EXEC SQL END DECLARE SECTION;
*/

#line 40 "pwdinit.sqc"


   unsigned int numsel = 999;       // menue var
   unsigned int maxsel = 0;
   struct sqlca sqlca;              // sqlca structure
   int ch, i = 0;                   // vars for enc_pwd input
   char *temp_pwd;                  // temp var for php_md5 func
   char tbspace[256];
   char hst[1000];
   char atext[4];


   switch( argc )
   {
	   case 2:
	   case 4:
	   		break;
	   default:
            printf ("\nUSAGE: %s database [userid passwd]\n\n", argv[0]);
            return 1;
            break;
   }


   // init connection vars

   db[0] = '\0';
   uid[0] = '\0';
   passwd[0] = '\0';

   user[0] = '\0';
   enc_pwd[0] = '\0';
   enc_pwd2[0] = '\0';
   enc_pwd_final[0] = '\0';

   switch( argc )
   {
       case 2:
          strcpy (db, argv[1]);
          
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 79 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 79 "pwdinit.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 79 "pwdinit.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 19;
#line 79 "pwdinit.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 79 "pwdinit.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 79 "pwdinit.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 79 "pwdinit.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 79 "pwdinit.sqc"
  sqlastop(0L);
}

#line 79 "pwdinit.sqc"

          EMB_SQL_CHECK("CONNECT TO DB");
          break;
       case 4:
          strcpy (db, argv[1]);
          strcpy (uid, argv[2]);
          strcpy (passwd, argv[3]);
          
/*
EXEC SQL CONNECT TO :db USER :uid USING :passwd;
*/

{
#line 86 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 86 "pwdinit.sqc"
  sqlaaloc(2,3,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 86 "pwdinit.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 19;
#line 86 "pwdinit.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 86 "pwdinit.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 86 "pwdinit.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 9;
#line 86 "pwdinit.sqc"
      sql_setdlist[1].sqldata = (void*)uid;
#line 86 "pwdinit.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 86 "pwdinit.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 19;
#line 86 "pwdinit.sqc"
      sql_setdlist[2].sqldata = (void*)passwd;
#line 86 "pwdinit.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 86 "pwdinit.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 86 "pwdinit.sqc"
  sqlacall((unsigned short)29,5,2,0,0L);
#line 86 "pwdinit.sqc"
  sqlastop(0L);
}

#line 86 "pwdinit.sqc"

          EMB_SQL_CHECK("CONNECT TO DB");
          break;
       default:
          printf ("\nUSAGE: %s database [userid passwd]\n\n", argv[0]);
          return 1;
          break;
   }


   // check if tables are there

   
/*
EXEC SQL SELECT count(tabname) INTO :there
       FROM syscat.tables
       WHERE tabschema = 'PWDSAFE' AND tabname = 'PWDLIST' OR tabname = 'PWDLOGIN';
*/

{
#line 100 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 100 "pwdinit.sqc"
  sqlaaloc(3,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 100 "pwdinit.sqc"
      sql_setdlist[0].sqltype = 500; sql_setdlist[0].sqllen = 2;
#line 100 "pwdinit.sqc"
      sql_setdlist[0].sqldata = (void*)&there;
#line 100 "pwdinit.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 100 "pwdinit.sqc"
      sqlasetdata(3,0,1,sql_setdlist,NULL,0L);
    }
#line 100 "pwdinit.sqc"
  sqlacall((unsigned short)24,1,0,3,0L);
#line 100 "pwdinit.sqc"
  sqlastop(0L);
}

#line 100 "pwdinit.sqc"


   if( there < 2 )
   {
       printf( "\nTables not in database\n\n" );
   	   printf( "Tablespace (leave blank for default tablespace: " );
   	   tbspace[0] = '\0';
	   fflush(stdin);
	   gets( tbspace );

   	   printf( "\n\nCreating tables..." );

   	   // create the tables

   	   if( strlen( tbspace ) == 0 )
   	   {

   	   //default tbs

   	   execi(

       "CREATE TABLE \"PWDSAFE\".\"PWDLIST\"  (					\
		  \"ACCOUNT\" VARCHAR(32) NOT NULL , 		\
		  \"USERID\" VARCHAR(32) NOT NULL , 		\
		  \"PASSWORD\" VARCHAR(32) FOR BIT DATA , 	\
		  \"DESCRIPTION\" VARCHAR(64) ,				\
		  \"USR\" VARCHAR(32) NOT NULL )"

	   );

       execi(

	   "CREATE TABLE \"PWDSAFE\".\"PWDLOGIN\"  (					\
 		  \"USR\" VARCHAR(32) NOT NULL , 				\
 		  \"PWD\" VARCHAR(32) NOT NULL ,				\
 		  \"ADMIN\" INTEGER NOT NULL WITH DEFAULT 0 )"
 	   );

       } else {

	   hst[0] = '\0';

	   sprintf( hst, "CREATE TABLE \"PWDSAFE\".\"PWDLIST\"  (					\
		  \"ACCOUNT\" VARCHAR(32) NOT NULL , 		\
		  \"USERID\" VARCHAR(32) NOT NULL , 		\
		  \"PASSWORD\" VARCHAR(32) FOR BIT DATA , 	\
		  \"DESCRIPTION\" VARCHAR(64) ,				\
		  \"USR\" VARCHAR(32) NOT NULL ) IN \"%s\"", tbspace );

       execi( hst );

       hst[0] = '\0';

       sprintf( hst, "CREATE TABLE \"PWDSAFE\".\"PWDLOGIN\"  (					\
 		  \"USR\" VARCHAR(32) NOT NULL , 				\
 		  \"PWD\" VARCHAR(32) NOT NULL ,				\
 		  \"ADMIN\" INTEGER NOT NULL WITH DEFAULT 0 ) IN \"%s\"" , tbspace );

       execi( hst );

       }

       // primary keys

       execi(

       "ALTER TABLE \"PWDSAFE\".\"PWDLIST\" 						\
	       ADD CONSTRAINT \"PK_PWDLIST\" PRIMARY KEY	\
	           (\"ACCOUNT\", \"USR\")"

       );

       execi(

       "ALTER TABLE \"PWDSAFE\".\"PWDLOGIN\" 						\
	       ADD CONSTRAINT \"PK_PWDLOGIN\" PRIMARY KEY	\
		       (\"USR\")"

       );

   }
}



int execi (char s[1000]) {

   strcpy(sqlstmt.stmt, s);

   sqlstmt.len = strlen(sqlstmt.stmt);

   
/*
EXEC SQL
      EXECUTE IMMEDIATE :sqlstmt;
*/

{
#line 192 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 192 "pwdinit.sqc"
  sqlastls( *(unsigned short *)&sqlstmt,(const char*)&sqlstmt+2,0L);
#line 192 "pwdinit.sqc"
  sqlacall((unsigned short)23,2,0,0,0L);
#line 192 "pwdinit.sqc"
  sqlastop(0L);
}

#line 192 "pwdinit.sqc"


   //EMB_SQL_CHECK("SQL Check");

   if( sqlca.sqlcode == -204 )
   {
      printf( "\n\nThe entered tablespace does not exist.\n" );
      
/*
EXEC SQL ROLLBACK;
*/

{
#line 199 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 199 "pwdinit.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 199 "pwdinit.sqc"
  sqlastop(0L);
}

#line 199 "pwdinit.sqc"

      
/*
EXEC SQL CONNECT RESET;
*/

{
#line 200 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 200 "pwdinit.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 200 "pwdinit.sqc"
  sqlastop(0L);
}

#line 200 "pwdinit.sqc"

      EMB_SQL_CHECK("CONNECT RESET");
      exit(99);
   }

   if( sqlca.sqlcode == -601 )
   {
      //printf( "\n\nTable already exists.\n" );
      
/*
EXEC SQL ROLLBACK;
*/

{
#line 208 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 208 "pwdinit.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 208 "pwdinit.sqc"
  sqlastop(0L);
}

#line 208 "pwdinit.sqc"

      return -601;
   }
   if( sqlca.sqlcode == -6244 )
   {
      //printf( "\n\nIndex already exists.\n" );
      
/*
EXEC SQL ROLLBACK;
*/

{
#line 214 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 214 "pwdinit.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 214 "pwdinit.sqc"
  sqlastop(0L);
}

#line 214 "pwdinit.sqc"

      return -624;
   }


   
/*
EXEC SQL COMMIT;
*/

{
#line 219 "pwdinit.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 219 "pwdinit.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 219 "pwdinit.sqc"
  sqlastop(0L);
}

#line 219 "pwdinit.sqc"


   EMB_SQL_CHECK("COMMIT");

   //printf( "\n%s\n", s );

   return 0;
}

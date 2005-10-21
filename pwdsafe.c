static char sqla_program_id[162] = 
{
 42,0,65,68,65,75,65,73,80,87,68,83,65,70,69,32,56,65,70,49,
 88,85,74,86,48,49,49,49,49,32,50,32,8,0,65,84,50,52,48,50,
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


static const short sqlIsLiteral   = SQL_IS_LITERAL;
static const short sqlIsInputHvar = SQL_IS_INPUT_HVAR;


#line 1 "pwdsafe.sqc"
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


#line 11 "pwdsafe.sqc"



int main(int argc, char *argv[]) {


   
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 17 "pwdsafe.sqc"

           char reguser[32];
           char regpwd[32];
           char user[32];           // var for actual user
           char pwd[34];            // host var for hashed pwd in pwdsafe.pwdlogin
           short admin;				// host var, if user is admin -> allow register new users
           short there;				// host var to check if tables are there
           char account[32];
           char userid[32];
           char password[32];
           char description[64];
           char haccount[32];
		   char huserid[32];
		   char hpassword[32];
           char hdescription[64];
           char enc_pwd[32];        // pwd entered
           char enc_pwd2[33];       // md5 hashed pwd
           char acc[32];            // host var for where clause
           char ts[32];
           short int tsind;			// indicator var for ts

           char uid[9];             // connection vars
           char passwd[19];
           char db[19];


   
/*
EXEC SQL END DECLARE SECTION;
*/

#line 43 "pwdsafe.sqc"


   unsigned int numsel = 999;       // menue var
   struct sqlca sqlca;              // sqlca structure
   int ch, i = 0;                   // vars for enc_pwd input
   char *temp_pwd;                  // temp var for php_md5 func
   int del, upd;			    	// delete and update var (y/n)
   FILE *fp;						// filepointer fp
   char filename[255];				// var for filename

   unsigned int maxsel;

   // init connection vars

   db[0] = '\0';
   uid[0] = '\0';
   passwd[0] = '\0';

   switch( argc )
   {
	   case 2:
	      strcpy (db, argv[1]);
	      
/*
EXEC SQL CONNECT TO :db;
*/

{
#line 65 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 65 "pwdsafe.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 65 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 19;
#line 65 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 65 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 65 "pwdsafe.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 65 "pwdsafe.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 65 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 65 "pwdsafe.sqc"

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
#line 72 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 72 "pwdsafe.sqc"
  sqlaaloc(2,3,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 72 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 19;
#line 72 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 72 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 72 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 9;
#line 72 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)uid;
#line 72 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 72 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 19;
#line 72 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)passwd;
#line 72 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 72 "pwdsafe.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 72 "pwdsafe.sqc"
  sqlacall((unsigned short)29,5,2,0,0L);
#line 72 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 72 "pwdsafe.sqc"

          EMB_SQL_CHECK("CONNECT TO DB");
          break;
       default:
          printf ("\nUSAGE: %s database [userid passwd]\n\n", argv[0]);
          return 1;
          break;
   }


   user[0] = '\0';
   pwd[0] = '\0';
   printf( "\nUser: "); scanf( "%s", user );
   printf( "\nPlease enter the encryption password: " );


   do
      {
         ch = _getch();
         switch( ch )
         {
   		     case 8:
   		        if( i != 0 )
   		        {
   		    	   i=i-1;
   		    	   printf( "d" );
   		    	}
   		        break;
   		     case 13:
   		        break;
   		     default:
   		        enc_pwd[i++] = ch;
   		        printf( "*" );
   		        break;
   	     }
      } while( ch != '\r' );

   enc_pwd[i] = '\0';


   //scanf( "%s", enc_pwd );
   temp_pwd = php_md5( enc_pwd );
   enc_pwd2[0] = '\0';
   strcpy( enc_pwd2, temp_pwd );
   free( temp_pwd );

   //printf( "\n%s\n%s\n", user, enc_pwd2 );  // debug

   
/*
EXEC SQL SELECT pwd, admin INTO :pwd, :admin
       FROM pwdsafe.pwdlogin
       WHERE usr = :user;
*/

{
#line 122 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 122 "pwdsafe.sqc"
  sqlaaloc(2,1,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 122 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 122 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)user;
#line 122 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 122 "pwdsafe.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 122 "pwdsafe.sqc"
  sqlaaloc(3,2,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 122 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 34;
#line 122 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)pwd;
#line 122 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 122 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 500; sql_setdlist[1].sqllen = 2;
#line 122 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)&admin;
#line 122 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 122 "pwdsafe.sqc"
      sqlasetdata(3,0,2,sql_setdlist,NULL,0L);
    }
#line 122 "pwdsafe.sqc"
  sqlacall((unsigned short)24,1,2,3,0L);
#line 122 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 122 "pwdsafe.sqc"


   //printf( "\n%s\n%s-\n%s-\n", user, enc_pwd2, pwd );  // debug

   if( sqlca.sqlcode == 100 )
   {
	   printf( "\n\nUser not found.\n" );
	   
/*
EXEC SQL CONNECT RESET;
*/

{
#line 129 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 129 "pwdsafe.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 129 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 129 "pwdsafe.sqc"

       EMB_SQL_CHECK("CONNECT RESET");
	   return 1;
   }
   EMB_SQL_CHECK("SELECT");


   if( strcmp( pwd, enc_pwd2 ) != 0)
   {
	   printf( "\n\nUser / Password do not match.\n" );
	   
/*
EXEC SQL CONNECT RESET;
*/

{
#line 139 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 139 "pwdsafe.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 139 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 139 "pwdsafe.sqc"

       EMB_SQL_CHECK("CONNECT RESET");
	   return 1;
   }

   printf("\n\n");
   printf("PwdSafe Application v1.2\n");

   do
      {
         numsel = 0;
         printf("\n\n");
         printf("************************************\n");
         printf(" 1 - Add entry\n");
         printf(" 2 - Search (fuzzy)\n");
         printf(" 3 - Search (exact)\n");
         printf(" 4 - Update Entry\n");
         printf(" 5 - Delete Entry\n");
         printf(" 6 - List all entries\n");
         printf(" 7 - Print all entries to .csv file\n" );
         printf(" 8 - Print all entries to file\n" );
         printf(" 9 - Change login password\n" );
         if( admin > 0 )
         {
            printf("10 - Register new user\n" );
         }
         printf("\n   Enter 0 to exit.\n");
         printf("************************************\n");

         printf("==> ");

         fflush(stdin);
         scanf("%u", &numsel);
         maxsel = 9;			// Max menue sections
         if( admin > 0 )
         {
			 maxsel++;
		 }
         if (numsel < 0 || numsel > maxsel)
            printf("\nInvalid selection. Please try again.\n");
         else
            if (numsel != 0)
            {
                switch (numsel)
				   {
				      // Search (exact)
				      case 3:
				          printf( "\nWhich account: " );
				          acc[0] = '\0';
						  fflush(stdin);
						  gets( acc );

						  account[0] = '\0';
						  userid[0] = '\0';
						  password[0] = '\0';
						  description[0] = '\0';

						  
/*
EXEC SQL SELECT account, userid, decrypt_char(password, :enc_pwd), description INTO :account, :userid, :password, :description
						              FROM pwdsafe.pwdlist
						              WHERE account = :acc AND usr = :user;
*/

{
#line 198 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 198 "pwdsafe.sqc"
  sqlaaloc(2,3,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 198 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 198 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 198 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 198 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 198 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)acc;
#line 198 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 198 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 198 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)user;
#line 198 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 198 "pwdsafe.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 198 "pwdsafe.sqc"
  sqlaaloc(3,4,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 198 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 198 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 198 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 198 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 198 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 198 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 198 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 198 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 198 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 198 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 64;
#line 198 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)description;
#line 198 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 198 "pwdsafe.sqc"
      sqlasetdata(3,0,4,sql_setdlist,NULL,0L);
    }
#line 198 "pwdsafe.sqc"
  sqlacall((unsigned short)24,2,2,3,0L);
#line 198 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 198 "pwdsafe.sqc"


						  switch( sqlca.sqlcode )
						  {
							  case 0:
							   		printf( "\nAccount    : %s", account );
						  			printf( "\nUserid     : %s", userid );
						  			printf( "\nPassword   : %s", password );
   						 			printf( "\nDescription: %s", description );
   						 			break;
   						 	  case 100:
   						 	  		printf( "\nAccount not found." );
   						 	  		break;
   						 	  case -20144:
   						 	  case -20145:
   						 	  		printf( "\nWrong decryption password.");
   						 			
/*
EXEC SQL ROLLBACK;
*/

{
#line 214 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 214 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 214 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 214 "pwdsafe.sqc"

   						 			return 1;
   						 			break;
   						 	  default:
   						 	  		EMB_SQL_CHECK("SELECT statement");
   						 	  		break;
						  }

   						  break;


					  // Search (fuzzy)
					  case 2:
					      printf( "\nWhich account: " );
					      acc[0] = '\0';
					      fflush(stdin);
						  gets( acc );

						  account[0] = '\0';
						  userid[0] = '\0';
						  password[0] = '\0';
						  description[0] = '\0';


						  
/*
EXEC SQL DECLARE c2 CURSOR FOR
					              SELECT account, userid, decrypt_char(password, :enc_pwd), description
						              FROM pwdsafe.pwdlist
						          WHERE usr = :user AND ucase(account) LIKE ucase('%' concat :acc concat '%')
						          ORDER BY account;
*/

#line 242 "pwdsafe.sqc"


/*
						  EXEC SQL DECLARE c2 CURSOR FOR
						  		  SELECT account, userid, decrypt_char(password, :enc_pwd), description
						  			  FROM pwdsafe.pwdlist
						  		  WHERE usr = :user AND account LIKE ':acc'
						          ORDER BY account;
*/
						  
/*
EXEC SQL OPEN c2;
*/

{
#line 251 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 251 "pwdsafe.sqc"
  sqlaaloc(2,3,7,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 251 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 251 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 251 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 251 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 251 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)user;
#line 251 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 251 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 251 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)acc;
#line 251 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 251 "pwdsafe.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 251 "pwdsafe.sqc"
  sqlacall((unsigned short)26,3,2,0,0L);
#line 251 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 251 "pwdsafe.sqc"

					      EMB_SQL_CHECK("OPEN CURSOR");

					      i=0;

					      do {
					         
/*
EXEC SQL FETCH c2 INTO :account, :userid, :password, :description;
*/

{
#line 257 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 257 "pwdsafe.sqc"
  sqlaaloc(3,4,8,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 257 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 257 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 257 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 257 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 257 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 257 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 257 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 257 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 257 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 257 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 64;
#line 257 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)description;
#line 257 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 257 "pwdsafe.sqc"
      sqlasetdata(3,0,4,sql_setdlist,NULL,0L);
    }
#line 257 "pwdsafe.sqc"
  sqlacall((unsigned short)25,3,0,3,0L);
#line 257 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 257 "pwdsafe.sqc"


					         if (SQLCODE != 0) break;

					         printf( "\nAccount    : %s", account );
							 printf( "\nUserid     : %s", userid );
							 printf( "\nPassword   : %s", password );
   						 	 printf( "\nDescription: %s", description );
   						 	 printf( "\n" );
   						 	 i++;
					      } while ( 1 );


					      switch( sqlca.sqlcode )
						  {
						   	  case -20144:
						   	  case -20145:
						   	  		printf( "\nWrong decryption password.");
						   			
/*
EXEC SQL ROLLBACK;
*/

{
#line 275 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 275 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 275 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 275 "pwdsafe.sqc"

						   			return 1;
						   			break;
						   	  case 100:
							     	if( i == 0 )
							     	    printf( "\nAccount not found." );
   						 	  		break;
						   	  default:
						   	  		break;
						  }

					      
/*
EXEC SQL CLOSE c2;
*/

{
#line 286 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 286 "pwdsafe.sqc"
  sqlacall((unsigned short)20,3,0,0,0L);
#line 286 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 286 "pwdsafe.sqc"

                          EMB_SQL_CHECK("CLOSE CURSOR");

                          break;


   					  // List all entries
   					  case 6:
   					      
/*
EXEC SQL DECLARE c1 CURSOR FOR
					              SELECT account, userid, decrypt_char(password, :enc_pwd), description
						              FROM pwdsafe.pwdlist
						          WHERE usr = :user
						          ORDER BY account;
*/

#line 298 "pwdsafe.sqc"


						  
/*
EXEC SQL OPEN c1;
*/

{
#line 300 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 300 "pwdsafe.sqc"
  sqlaaloc(2,2,9,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 300 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 300 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 300 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 300 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 300 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)user;
#line 300 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 300 "pwdsafe.sqc"
      sqlasetdata(2,0,2,sql_setdlist,NULL,0L);
    }
#line 300 "pwdsafe.sqc"
  sqlacall((unsigned short)26,4,2,0,0L);
#line 300 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 300 "pwdsafe.sqc"

					      EMB_SQL_CHECK("OPEN CURSOR");

					      do {
					         
/*
EXEC SQL FETCH c1 INTO :account, :userid, :password, :description;
*/

{
#line 304 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 304 "pwdsafe.sqc"
  sqlaaloc(3,4,10,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 304 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 304 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 304 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 304 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 304 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 304 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 304 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 304 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 304 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 304 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 64;
#line 304 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)description;
#line 304 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 304 "pwdsafe.sqc"
      sqlasetdata(3,0,4,sql_setdlist,NULL,0L);
    }
#line 304 "pwdsafe.sqc"
  sqlacall((unsigned short)25,4,0,3,0L);
#line 304 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 304 "pwdsafe.sqc"


					         if (SQLCODE != 0) break;

					         printf( "\nAccount    : %s", account );
							 printf( "\nUserid     : %s", userid );
							 printf( "\nPassword   : %s", password );
   						 	 printf( "\nDescription: %s", description );
   						 	 printf( "\n" );
					      } while ( 1 );


					      switch( sqlca.sqlcode )
						  {
						   	  case -20144:
						   	  case -20145:
						   	  		printf( "\nWrong decryption password.");
						   			
/*
EXEC SQL ROLLBACK;
*/

{
#line 321 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 321 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 321 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 321 "pwdsafe.sqc"

						   			return 1;
						   			break;
						   	  default:
						   	  		break;
						  }

					      
/*
EXEC SQL CLOSE c1;
*/

{
#line 328 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 328 "pwdsafe.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 328 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 328 "pwdsafe.sqc"

                          EMB_SQL_CHECK("CLOSE CURSOR");

                          break;


				      // Add entry
				      case 1:
				          account[0] = '\0';
						  userid[0] = '\0';
						  password[0] = '\0';
						  description[0] = '\0';
						  fflush(stdin);

						  printf( "\nAccount    : " ); gets( account );
						  if( strlen( account ) == 0 )
						     break;
						  printf( "Userid     : " ); gets( userid );
						  printf( "Password   : " ); gets( password );
   						  printf( "Description: " ); gets( description );

   						  // read description as sentence

   						  
/*
EXEC SQL INSERT INTO pwdsafe.pwdlist (account,userid,password,description,usr,ts) values
   						      (:account, :userid, encrypt(:password, :enc_pwd), :description, :user, current timestamp);
*/

{
#line 352 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 352 "pwdsafe.sqc"
  sqlaaloc(2,6,11,0L);
    {
      struct sqla_setdata_list sql_setdlist[6];
#line 352 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 352 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 352 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 352 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 352 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 352 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 352 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 352 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 352 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 352 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 32;
#line 352 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)enc_pwd;
#line 352 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 352 "pwdsafe.sqc"
      sql_setdlist[4].sqltype = 460; sql_setdlist[4].sqllen = 64;
#line 352 "pwdsafe.sqc"
      sql_setdlist[4].sqldata = (void*)description;
#line 352 "pwdsafe.sqc"
      sql_setdlist[4].sqlind = 0L;
#line 352 "pwdsafe.sqc"
      sql_setdlist[5].sqltype = 460; sql_setdlist[5].sqllen = 32;
#line 352 "pwdsafe.sqc"
      sql_setdlist[5].sqldata = (void*)user;
#line 352 "pwdsafe.sqc"
      sql_setdlist[5].sqlind = 0L;
#line 352 "pwdsafe.sqc"
      sqlasetdata(2,0,6,sql_setdlist,NULL,0L);
    }
#line 352 "pwdsafe.sqc"
  sqlacall((unsigned short)24,5,2,0,0L);
#line 352 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 352 "pwdsafe.sqc"


   						  // -803 duplicate rows - constraint violation

   						  if( sqlca.sqlcode == -803 )
						  {
						  	  printf( "\nAccount already exists.\n" );
						  	  
/*
EXEC SQL ROLLBACK;
*/

{
#line 359 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 359 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 359 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 359 "pwdsafe.sqc"

						  	  break;
						  }
						  else {
						  	  EMB_SQL_CHECK("INSERT");
						  	  
/*
EXEC SQL COMMIT;
*/

{
#line 364 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 364 "pwdsafe.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 364 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 364 "pwdsafe.sqc"

						  }

				          break;

				      // Update Entry
				      case 4:
				          printf( "\nWhich account: " );
						  acc[0] = '\0';
						  fflush(stdin);
						  gets( acc );

						  
/*
EXEC SQL DECLARE c5 CURSOR FOR
					              SELECT account, userid, decrypt_char(password, :enc_pwd), description
						             FROM pwdsafe.pwdlist
						          WHERE usr = :user AND ucase(account) LIKE ucase('%' concat :acc concat '%')
						          FOR UPDATE;
*/

#line 380 "pwdsafe.sqc"


						  
/*
EXEC SQL OPEN c5;
*/

{
#line 382 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 382 "pwdsafe.sqc"
  sqlaaloc(2,3,12,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 382 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 382 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 382 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 382 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 382 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)user;
#line 382 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 382 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 382 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)acc;
#line 382 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 382 "pwdsafe.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 382 "pwdsafe.sqc"
  sqlacall((unsigned short)26,6,2,0,0L);
#line 382 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 382 "pwdsafe.sqc"

						  EMB_SQL_CHECK("OPEN CURSOR");

                          i=0;

						  do {
						      account[0] = '\0';
							  userid[0] = '\0';
							  password[0] = '\0';
						      description[0] = '\0';

						      haccount[0] = '\0';
							  huserid[0] = '\0';
							  hpassword[0] = '\0';
							  hdescription[0] = '\0';

							  fflush(stdin);

						      
/*
EXEC SQL FETCH c5 INTO :account, :userid, :password, :description;
*/

{
#line 400 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 400 "pwdsafe.sqc"
  sqlaaloc(3,4,13,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 400 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 400 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 400 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 400 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 400 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 400 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 400 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 400 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 400 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 400 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 64;
#line 400 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)description;
#line 400 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 400 "pwdsafe.sqc"
      sqlasetdata(3,0,4,sql_setdlist,NULL,0L);
    }
#line 400 "pwdsafe.sqc"
  sqlacall((unsigned short)25,6,0,3,0L);
#line 400 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 400 "pwdsafe.sqc"

						      if (SQLCODE != 0) break;

						      do {
							  printf( "\n1. Account    : %s", account );
							  printf( "\n2. Userid     : %s", userid );
							  printf( "\n3. Password   : %s", password );
							  printf( "\n4. Description: %s", description );
   						 	  printf( "\n" );

						      printf( "Update? (1/2/3/4/n) Main Menue (q)" );
						      upd = 0;
						      scanf( "%c", &upd );

						      fflush(stdin);

						      switch( upd )
						      {
								  case '1':
								     printf( "\nAccount: " ); gets( haccount );

								     
/*
EXEC SQL UPDATE pwdsafe.pwdlist SET account = :haccount, ts = current timestamp
									          WHERE CURRENT OF c5;
*/

{
#line 422 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 422 "pwdsafe.sqc"
  sqlaaloc(2,1,14,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 422 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 422 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)haccount;
#line 422 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 422 "pwdsafe.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 422 "pwdsafe.sqc"
  sqlacall((unsigned short)24,7,2,0,0L);
#line 422 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 422 "pwdsafe.sqc"


									 if( sqlca.sqlcode == -803 )
									    printf( "\nAccount already exists.\n" );

									 strcpy( account, haccount );
									 break;
								  case '2':
								     printf( "\nUserid: " ); gets( huserid );

								     
/*
EXEC SQL UPDATE pwdsafe.pwdlist SET userid = :huserid, ts = current timestamp
									          WHERE CURRENT OF c5;
*/

{
#line 433 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 433 "pwdsafe.sqc"
  sqlaaloc(2,1,15,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 433 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 433 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)huserid;
#line 433 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 433 "pwdsafe.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 433 "pwdsafe.sqc"
  sqlacall((unsigned short)24,8,2,0,0L);
#line 433 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 433 "pwdsafe.sqc"

         							 EMB_SQL_CHECK("UPDATE");

								     strcpy( userid, huserid );
								     break;
								  case '3':
								     printf( "\nPassword: " ); gets( hpassword );

								     
/*
EXEC SQL UPDATE pwdsafe.pwdlist SET password = encrypt(:hpassword, :enc_pwd), ts = current timestamp
									          WHERE CURRENT OF c5;
*/

{
#line 442 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 442 "pwdsafe.sqc"
  sqlaaloc(2,2,16,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 442 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 442 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)hpassword;
#line 442 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 442 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 442 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)enc_pwd;
#line 442 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 442 "pwdsafe.sqc"
      sqlasetdata(2,0,2,sql_setdlist,NULL,0L);
    }
#line 442 "pwdsafe.sqc"
  sqlacall((unsigned short)24,9,2,0,0L);
#line 442 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 442 "pwdsafe.sqc"

         							 EMB_SQL_CHECK("UPDATE");

								     strcpy( password, hpassword );
								     break;
								  case '4':
								     printf( "\nDescription: " ); gets( hdescription );

								     
/*
EXEC SQL UPDATE pwdsafe.pwdlist SET description = :hdescription, ts = current timestamp
									          WHERE CURRENT OF c5;
*/

{
#line 451 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 451 "pwdsafe.sqc"
  sqlaaloc(2,1,17,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 451 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 64;
#line 451 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)hdescription;
#line 451 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 451 "pwdsafe.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 451 "pwdsafe.sqc"
  sqlacall((unsigned short)24,10,2,0,0L);
#line 451 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 451 "pwdsafe.sqc"

         							 EMB_SQL_CHECK("UPDATE");

								     strcpy( description, hdescription );
								     break;
								  case 'q':
								     goto eloop_upd;
								     break;
								  default:
								     break;
							  }
						      } while ( upd != 'n' );
							  i++;

						  } while ( 1 );

                          switch( sqlca.sqlcode )
						  {
						   	  case -20144:
						   	  case -20145:
						   	     printf( "\nWrong decryption password.");
						  		 
/*
EXEC SQL ROLLBACK;
*/

{
#line 472 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 472 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 472 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 472 "pwdsafe.sqc"

						     	 return 1;
						  		 break;
						  	  case -803:
						  	     printf( "\nAccount already exists.\n" );
								 
/*
EXEC SQL ROLLBACK;
*/

{
#line 477 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 477 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 477 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 477 "pwdsafe.sqc"

								 break;
						  	  case 100:
						       	 if( i == 0 )
						       	    printf( "\nAccount not found." );
						   		 break;
						   	  default:
						   		 break;
						  }

						  eloop_upd:

						  
/*
EXEC SQL CLOSE c5;
*/

{
#line 489 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 489 "pwdsafe.sqc"
  sqlacall((unsigned short)20,6,0,0,0L);
#line 489 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 489 "pwdsafe.sqc"

						  EMB_SQL_CHECK("CLOSE CURSOR");

						  
/*
EXEC SQL COMMIT;
*/

{
#line 492 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 492 "pwdsafe.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 492 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 492 "pwdsafe.sqc"

						  EMB_SQL_CHECK("COMMIT");

				          break;

				      // Delete Entry
				      case 5:
				          printf( "\nWhich account: " );
						  acc[0] = '\0';
						  fflush(stdin);
						  gets( acc );

						  
/*
EXEC SQL DECLARE c4 CURSOR FOR
					              SELECT account, userid, decrypt_char(password, :enc_pwd), description
						             FROM pwdsafe.pwdlist
						          WHERE usr = :user AND ucase(account) LIKE ucase('%' concat :acc concat '%')
						          FOR UPDATE;
*/

#line 508 "pwdsafe.sqc"


						  
/*
EXEC SQL OPEN c4;
*/

{
#line 510 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 510 "pwdsafe.sqc"
  sqlaaloc(2,3,18,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 510 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 510 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 510 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 510 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 510 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)user;
#line 510 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 510 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 510 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)acc;
#line 510 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 510 "pwdsafe.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 510 "pwdsafe.sqc"
  sqlacall((unsigned short)26,11,2,0,0L);
#line 510 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 510 "pwdsafe.sqc"

						  EMB_SQL_CHECK("OPEN CURSOR");

                          i=0;

						  do {
						      account[0] = '\0';
							  userid[0] = '\0';
							  password[0] = '\0';
						      description[0] = '\0';

						      
/*
EXEC SQL FETCH c4 INTO :account, :userid, :password, :description;
*/

{
#line 521 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 521 "pwdsafe.sqc"
  sqlaaloc(3,4,19,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 521 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 521 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 521 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 521 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 521 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 521 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 521 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 521 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 521 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 521 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 64;
#line 521 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)description;
#line 521 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 521 "pwdsafe.sqc"
      sqlasetdata(3,0,4,sql_setdlist,NULL,0L);
    }
#line 521 "pwdsafe.sqc"
  sqlacall((unsigned short)25,11,0,3,0L);
#line 521 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 521 "pwdsafe.sqc"

						      if (SQLCODE != 0) break;

						      printf( "\nAccount    : %s", account );
							  printf( "\nUserid     : %s", userid );
							  printf( "\nPassword   : %s", password );
							  printf( "\nDescription: %s", description );
   						 	  printf( "\n" );

						      printf( "Delete? (y/n) Main Menue (q)" );
						      del = 0;
						      fflush(stdin);
						      scanf( "%c", &del );

						      switch( del )
						      {
								  case 'y':
								     
/*
EXEC SQL DELETE FROM pwdsafe.pwdlist WHERE CURRENT OF c4;
*/

{
#line 538 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 538 "pwdsafe.sqc"
  sqlacall((unsigned short)24,12,0,0,0L);
#line 538 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 538 "pwdsafe.sqc"

						             EMB_SQL_CHECK("DELETE");
								     break;
								  case 'q':
								     goto eloop_del;
								     break;
								  default:
								     break;
							  }
							  i++;

						  } while ( 1 );

                          switch( sqlca.sqlcode )
						  {
						   	  case -20144:
						   	  case -20145:
						   	     printf( "\nWrong decryption password.");
						  		 
/*
EXEC SQL ROLLBACK;
*/

{
#line 556 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 556 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 556 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 556 "pwdsafe.sqc"

						     	 return 1;
						  		 break;
						  	  case 100:
						       	 if( i == 0 )
						       	    printf( "\nAccount not found." );
						   		 break;
						   	  default:
						   		 break;
						  }

						  eloop_del:

						  
/*
EXEC SQL CLOSE c4;
*/

{
#line 569 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 569 "pwdsafe.sqc"
  sqlacall((unsigned short)20,11,0,0,0L);
#line 569 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 569 "pwdsafe.sqc"

						  EMB_SQL_CHECK("CLOSE CURSOR");

						  
/*
EXEC SQL COMMIT;
*/

{
#line 572 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 572 "pwdsafe.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 572 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 572 "pwdsafe.sqc"

						  EMB_SQL_CHECK("COMMIT");

				          break;

				      // Register new user
				      case 10:
					  	  reguser[0] = '\0';
					  	  regpwd[0] = '\0';

					      printf( "\nUser    : " ); scanf( "%s", reguser );
					  	  printf( "Pwd     : " ); scanf( "%s", regpwd );

					  	  if(strlen(regpwd) < 6)
					  	  {
							  printf( "\n\nPassword has to be at least 6 bytes.\n" );
							  break;
						  }

					  	  temp_pwd = php_md5( regpwd );
						  enc_pwd2[0] = '\0';
						  strcpy( enc_pwd2, temp_pwd );
                          free( temp_pwd );

					      
/*
EXEC SQL INSERT INTO pwdsafe.pwdlogin (usr,pwd) values
					           (:reguser, :enc_pwd2);
*/

{
#line 597 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 597 "pwdsafe.sqc"
  sqlaaloc(2,2,20,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 597 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 597 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)reguser;
#line 597 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 597 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 33;
#line 597 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)enc_pwd2;
#line 597 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 597 "pwdsafe.sqc"
      sqlasetdata(2,0,2,sql_setdlist,NULL,0L);
    }
#line 597 "pwdsafe.sqc"
  sqlacall((unsigned short)24,13,2,0,0L);
#line 597 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 597 "pwdsafe.sqc"


					      // -803 duplicate rows - constraint violation

					      if( sqlca.sqlcode == -803 )
					      {
							  printf( "\nUser already exists.\n" );
							  
/*
EXEC SQL ROLLBACK;
*/

{
#line 604 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 604 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 604 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 604 "pwdsafe.sqc"

							  break;
						  }
						  else {
							  EMB_SQL_CHECK("INSERT");
							  
/*
EXEC SQL COMMIT;
*/

{
#line 609 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 609 "pwdsafe.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 609 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 609 "pwdsafe.sqc"

						  }

   						  break;

                      // print to csv file
                      case 7:
                          printf( "\nEnter [path]filename: " );
						  filename[0] = '\0';
						  fflush(stdin);
						  gets( filename );

                          if( strlen( filename ) == 0 )
                             fp = fopen( "pwdfile.csv", "w" );
						  else
                             fp = fopen( filename, "w" );

                          
/*
EXEC SQL DECLARE c6 CURSOR FOR
					              SELECT account, userid, decrypt_char(password, :enc_pwd), description, ts
						              FROM pwdsafe.pwdlist
						          WHERE usr = :user
						          ORDER BY account;
*/

#line 630 "pwdsafe.sqc"


						  
/*
EXEC SQL OPEN c6;
*/

{
#line 632 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 632 "pwdsafe.sqc"
  sqlaaloc(2,2,21,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 632 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 632 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 632 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 632 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 632 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)user;
#line 632 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 632 "pwdsafe.sqc"
      sqlasetdata(2,0,2,sql_setdlist,NULL,0L);
    }
#line 632 "pwdsafe.sqc"
  sqlacall((unsigned short)26,14,2,0,0L);
#line 632 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 632 "pwdsafe.sqc"

					      EMB_SQL_CHECK("OPEN CURSOR");

					      do {
					         
/*
EXEC SQL FETCH c6 INTO :account, :userid, :password, :description, :ts INDICATOR :tsind;
*/

{
#line 636 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 636 "pwdsafe.sqc"
  sqlaaloc(3,5,22,0L);
    {
      struct sqla_setdata_list sql_setdlist[5];
#line 636 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 636 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 636 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 636 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 636 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 636 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 636 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 636 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 636 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 636 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 64;
#line 636 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)description;
#line 636 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 636 "pwdsafe.sqc"
      sql_setdlist[4].sqltype = 461; sql_setdlist[4].sqllen = 32;
#line 636 "pwdsafe.sqc"
      sql_setdlist[4].sqldata = (void*)ts;
#line 636 "pwdsafe.sqc"
      sql_setdlist[4].sqlind = &tsind;
#line 636 "pwdsafe.sqc"
      sqlasetdata(3,0,5,sql_setdlist,NULL,0L);
    }
#line 636 "pwdsafe.sqc"
  sqlacall((unsigned short)25,14,0,3,0L);
#line 636 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 636 "pwdsafe.sqc"


					         if (SQLCODE != 0) break;

					         fprintf( fp, "\"%s\",", account );
							 fprintf( fp, "\"%s\",", userid );
							 fprintf( fp, "\"%s\",", password );
   						 	 fprintf( fp, "\"%s\"", description );
   						 	 if( tsind >= 0 )
   						 	    fprintf( fp, ",\"%s\"", ts );
   						 	 fprintf( fp, "\n" );
					      } while ( 1 );


					      switch( sqlca.sqlcode )
						  {
						   	  case -20144:
						   	  case -20145:
						   	  		printf( "\nWrong decryption password.");
						   			
/*
EXEC SQL ROLLBACK;
*/

{
#line 655 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 655 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 655 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 655 "pwdsafe.sqc"

						   			return 1;
						   			break;
						   	  default:
						   	  		break;
						  }

					      
/*
EXEC SQL CLOSE c6;
*/

{
#line 662 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 662 "pwdsafe.sqc"
  sqlacall((unsigned short)20,14,0,0,0L);
#line 662 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 662 "pwdsafe.sqc"

                          EMB_SQL_CHECK("CLOSE CURSOR");

					      fclose( fp );

                          break;


                      // print to file
                      case 8:
                          printf( "\nEnter [path]filename: " );
						  filename[0] = '\0';
						  fflush(stdin);
						  gets( filename );

                          if( strlen( filename ) == 0 )
                             fp = fopen( "pwdfile.txt", "w" );
						  else
                             fp = fopen( filename, "w" );

                          
/*
EXEC SQL DECLARE c7 CURSOR FOR
					              SELECT account, userid, decrypt_char(password, :enc_pwd), description
						              FROM pwdsafe.pwdlist
						          WHERE usr = :user
						          ORDER BY account;
*/

#line 686 "pwdsafe.sqc"


						  
/*
EXEC SQL OPEN c7;
*/

{
#line 688 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 688 "pwdsafe.sqc"
  sqlaaloc(2,2,23,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 688 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 688 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 688 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 688 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 688 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)user;
#line 688 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 688 "pwdsafe.sqc"
      sqlasetdata(2,0,2,sql_setdlist,NULL,0L);
    }
#line 688 "pwdsafe.sqc"
  sqlacall((unsigned short)26,15,2,0,0L);
#line 688 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 688 "pwdsafe.sqc"

					      EMB_SQL_CHECK("OPEN CURSOR");

					      do {
					         
/*
EXEC SQL FETCH c7 INTO :account, :userid, :password, :description;
*/

{
#line 692 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 692 "pwdsafe.sqc"
  sqlaaloc(3,4,24,0L);
    {
      struct sqla_setdata_list sql_setdlist[4];
#line 692 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 692 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)account;
#line 692 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 692 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 692 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)userid;
#line 692 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 692 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 692 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)password;
#line 692 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 692 "pwdsafe.sqc"
      sql_setdlist[3].sqltype = 460; sql_setdlist[3].sqllen = 64;
#line 692 "pwdsafe.sqc"
      sql_setdlist[3].sqldata = (void*)description;
#line 692 "pwdsafe.sqc"
      sql_setdlist[3].sqlind = 0L;
#line 692 "pwdsafe.sqc"
      sqlasetdata(3,0,4,sql_setdlist,NULL,0L);
    }
#line 692 "pwdsafe.sqc"
  sqlacall((unsigned short)25,15,0,3,0L);
#line 692 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 692 "pwdsafe.sqc"


					         if (SQLCODE != 0) break;

					         fprintf( fp, "\nAccount    : %s", account );
							 fprintf( fp, "\nUserid     : %s", userid );
							 fprintf( fp, "\nPassword   : %s", password );
   						 	 fprintf( fp, "\nDescription: %s", description );
   						 	 fprintf( fp, "\n" );
					      } while ( 1 );


					      switch( sqlca.sqlcode )
						  {
						   	  case -20144:
						   	  case -20145:
						   	  		printf( "\nWrong decryption password.");
						   			
/*
EXEC SQL ROLLBACK;
*/

{
#line 709 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 709 "pwdsafe.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 709 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 709 "pwdsafe.sqc"

						   			return 1;
						   			break;
						   	  default:
						   	  		break;
						  }

					      
/*
EXEC SQL CLOSE c7;
*/

{
#line 716 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 716 "pwdsafe.sqc"
  sqlacall((unsigned short)20,15,0,0,0L);
#line 716 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 716 "pwdsafe.sqc"

                          EMB_SQL_CHECK("CLOSE CURSOR");

					      fclose( fp );

                          break;

					  // Change login password
				      case 9:
					  	  regpwd[0] = '\0';

					      printf( "\nNew password: " ); scanf( "%s", regpwd );

					  	  if(strlen(regpwd) < 6)
					  	  {
							  printf( "\n\nPassword has to be at least 6 bytes.\n" );
							  break;
						  }

					  	  temp_pwd = php_md5( regpwd );
						  enc_pwd2[0] = '\0';
						  strcpy( enc_pwd2, temp_pwd );
                          free( temp_pwd );

					      
/*
EXEC SQL BEGIN COMPOUND ATOMIC STATIC
					         UPDATE pwdsafe.pwdlist
					            SET password = encrypt( decrypt_char( password, :enc_pwd ), :regpwd )
					         WHERE usr = :user;
*/

{
#line 743 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 743 "pwdsafe.sqc"
  sqlaaloc(2,3,25,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 743 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 743 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd;
#line 743 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 743 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 743 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)regpwd;
#line 743 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 743 "pwdsafe.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 32;
#line 743 "pwdsafe.sqc"
      sql_setdlist[2].sqldata = (void*)user;
#line 743 "pwdsafe.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 743 "pwdsafe.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 743 "pwdsafe.sqc"
  sqlacmpd((unsigned short)24,16,2,0,0L);

/*

					         UPDATE pwdsafe.pwdlogin
					            SET pwd = :enc_pwd2
					         WHERE usr = :user;
*/
#line 747 "pwdsafe.sqc"
  sqlaaloc(3,2,26,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 747 "pwdsafe.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 33;
#line 747 "pwdsafe.sqc"
      sql_setdlist[0].sqldata = (void*)enc_pwd2;
#line 747 "pwdsafe.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 747 "pwdsafe.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 32;
#line 747 "pwdsafe.sqc"
      sql_setdlist[1].sqldata = (void*)user;
#line 747 "pwdsafe.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 747 "pwdsafe.sqc"
      sqlasetdata(3,0,2,sql_setdlist,NULL,0L);
    }
#line 747 "pwdsafe.sqc"
  sqlacmpd((unsigned short)24,17,3,0,0L);

/*

						     COMMIT ;
*/
#line 749 "pwdsafe.sqc"
  sqlacmpd((unsigned short)21,0,0,0,0L);

/*
						  END COMPOUND ;
*/
#line 750 "pwdsafe.sqc"
  sqlacall((unsigned short)30,0,0,0,0L);
#line 750 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 750 "pwdsafe.sqc"


					      if( sqlca.sqlcode == 0 )
					      {
							  enc_pwd[0] = '\0';
							  strcpy( enc_pwd, regpwd );
						  }

					      break;

				      default:
				          printf("\nError in Reset... should not happen... exiting...\n");
				          exit(99);
				          break;
                   }  /* switch numsel */

            } /* if */

   } while (numsel != 0);


   
/*
EXEC SQL CONNECT RESET;
*/

{
#line 771 "pwdsafe.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 771 "pwdsafe.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 771 "pwdsafe.sqc"
  sqlastop(0L);
}

#line 771 "pwdsafe.sqc"

   EMB_SQL_CHECK("CONNECT RESET");
   return 0;
}



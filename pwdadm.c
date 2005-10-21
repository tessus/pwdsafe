static char sqla_program_id[162] = 
{
 42,0,65,68,65,75,65,73,80,87,68,65,68,77,32,32,76,65,89,121,
 82,79,75,85,48,49,49,49,49,32,50,32,8,0,65,84,50,52,48,50,
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


#line 1 "pwdadm.sqc"
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


#line 11 "pwdadm.sqc"



int main(int argc, char *argv[]) {

   
/*
EXEC SQL BEGIN DECLARE SECTION;
*/

#line 16 "pwdadm.sqc"

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

#line 31 "pwdadm.sqc"


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
#line 70 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 70 "pwdadm.sqc"
  sqlaaloc(2,1,1,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 70 "pwdadm.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 19;
#line 70 "pwdadm.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 70 "pwdadm.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 70 "pwdadm.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 70 "pwdadm.sqc"
  sqlacall((unsigned short)29,4,2,0,0L);
#line 70 "pwdadm.sqc"
  sqlastop(0L);
}

#line 70 "pwdadm.sqc"

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
#line 77 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 77 "pwdadm.sqc"
  sqlaaloc(2,3,2,0L);
    {
      struct sqla_setdata_list sql_setdlist[3];
#line 77 "pwdadm.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 19;
#line 77 "pwdadm.sqc"
      sql_setdlist[0].sqldata = (void*)db;
#line 77 "pwdadm.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 77 "pwdadm.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 9;
#line 77 "pwdadm.sqc"
      sql_setdlist[1].sqldata = (void*)uid;
#line 77 "pwdadm.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 77 "pwdadm.sqc"
      sql_setdlist[2].sqltype = 460; sql_setdlist[2].sqllen = 19;
#line 77 "pwdadm.sqc"
      sql_setdlist[2].sqldata = (void*)passwd;
#line 77 "pwdadm.sqc"
      sql_setdlist[2].sqlind = 0L;
#line 77 "pwdadm.sqc"
      sqlasetdata(2,0,3,sql_setdlist,NULL,0L);
    }
#line 77 "pwdadm.sqc"
  sqlacall((unsigned short)29,5,2,0,0L);
#line 77 "pwdadm.sqc"
  sqlastop(0L);
}

#line 77 "pwdadm.sqc"

          EMB_SQL_CHECK("CONNECT TO DB");
          break;
       default:
          printf ("\nUSAGE: %s database [userid passwd]\n\n", argv[0]);
          return 1;
          break;
   }

   printf("\n\n");
   printf("PwdSafe Admin Tool v1.1\n");

   do
   {
       numsel = 0;
       printf("\n\n");
       printf("********************************\n");
       printf(" 1 - Register user\n");
       printf(" 2 - Set admin flag for user\n");
       printf(" 3 - Remove admin flag for user\n");
       printf(" 4 - List all users\n");
       printf("\n   Enter 0 to exit.\n");
       printf("********************************\n");

       printf("==> ");

       fflush(stdin);
       scanf("%u", &numsel);
       maxsel = 4;			// Max menue sections

       if (numsel < 0 || numsel > maxsel)
          printf("\nInvalid selection. Please try again.\n");
       else
       if (numsel != 0)
       {
          switch (numsel)
	 	  {
			 // Register new user
			 case 1:
			    user[0] = '\0';
				enc_pwd[0] = '\0';
				enc_pwd2[0] = '\0';
                enc_pwd_final[0] = '\0';


			    printf( "\nUser: "); scanf( "%s", user );
	            i = 0;
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

				if(strlen(enc_pwd) < 6)
				{
				   printf( "\n\nPassword has to be at least 6 bytes.\n" );
				   break;
				}

				i = 0;
				printf( "\nPlease enter the encryption password again: " );
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
				           enc_pwd2[i++] = ch;
				           printf( "*" );
				           break;
				   }
				} while( ch != '\r' );

				enc_pwd2[i] = '\0';

				if( strcmp( enc_pwd, enc_pwd2 ) != 0 )
				{
				   printf( "\n\nPasswords do not match.\n" );
				   break;
			    }

			    temp_pwd = php_md5( enc_pwd );
				enc_pwd_final[0] = '\0';
				strcpy( enc_pwd_final, temp_pwd );
				free( temp_pwd );


				
/*
EXEC SQL INSERT INTO pwdsafe.pwdlogin (usr,pwd) values
				     (:user, :enc_pwd_final);
*/

{
#line 192 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 192 "pwdadm.sqc"
  sqlaaloc(2,2,3,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 192 "pwdadm.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 192 "pwdadm.sqc"
      sql_setdlist[0].sqldata = (void*)user;
#line 192 "pwdadm.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 192 "pwdadm.sqc"
      sql_setdlist[1].sqltype = 460; sql_setdlist[1].sqllen = 33;
#line 192 "pwdadm.sqc"
      sql_setdlist[1].sqldata = (void*)enc_pwd_final;
#line 192 "pwdadm.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 192 "pwdadm.sqc"
      sqlasetdata(2,0,2,sql_setdlist,NULL,0L);
    }
#line 192 "pwdadm.sqc"
  sqlacall((unsigned short)24,1,2,0,0L);
#line 192 "pwdadm.sqc"
  sqlastop(0L);
}

#line 192 "pwdadm.sqc"


				// -803 duplicate rows - constraint violation

				if( sqlca.sqlcode == -803 )
				{
				  printf( "\n\nUser already exists.\n" );
				  
/*
EXEC SQL ROLLBACK;
*/

{
#line 199 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 199 "pwdadm.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 199 "pwdadm.sqc"
  sqlastop(0L);
}

#line 199 "pwdadm.sqc"

				}
				else {
				  EMB_SQL_CHECK("INSERT");
				  printf( "\n\nUser registered.\n" );
				  
/*
EXEC SQL COMMIT;
*/

{
#line 204 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 204 "pwdadm.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 204 "pwdadm.sqc"
  sqlastop(0L);
}

#line 204 "pwdadm.sqc"

               }

			   break;

			 // Set admin flag for user
			 case 2:

                huser[0] = '\0';
                fflush(stdin);
	            printf( "\nUser: " ); gets( huser );

			    
/*
EXEC SQL UPDATE pwdsafe.pwdlogin SET admin = 1 WHERE usr = :huser;
*/

{
#line 216 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 216 "pwdadm.sqc"
  sqlaaloc(2,1,4,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 216 "pwdadm.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 216 "pwdadm.sqc"
      sql_setdlist[0].sqldata = (void*)huser;
#line 216 "pwdadm.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 216 "pwdadm.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 216 "pwdadm.sqc"
  sqlacall((unsigned short)24,2,2,0,0L);
#line 216 "pwdadm.sqc"
  sqlastop(0L);
}

#line 216 "pwdadm.sqc"


                switch( sqlca.sqlcode )
                {
					case 100:
					   printf( "\nUser does not exist.\n" );
					   
/*
EXEC SQL ROLLBACK;
*/

{
#line 222 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 222 "pwdadm.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 222 "pwdadm.sqc"
  sqlastop(0L);
}

#line 222 "pwdadm.sqc"

					   break;
					default:
					   printf( "\nAdmin flag set.\n" );
					   
/*
EXEC SQL COMMIT;
*/

{
#line 226 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 226 "pwdadm.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 226 "pwdadm.sqc"
  sqlastop(0L);
}

#line 226 "pwdadm.sqc"

					   break;
				}

         		break;

             // Remove admin flag for user
 			 case 3:

                huser[0] = '\0';
                fflush(stdin);
	            printf( "\nUser: " ); gets( huser );

 			    
/*
EXEC SQL UPDATE pwdsafe.pwdlogin SET admin = 0 WHERE usr = :huser;
*/

{
#line 239 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 239 "pwdadm.sqc"
  sqlaaloc(2,1,5,0L);
    {
      struct sqla_setdata_list sql_setdlist[1];
#line 239 "pwdadm.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 239 "pwdadm.sqc"
      sql_setdlist[0].sqldata = (void*)huser;
#line 239 "pwdadm.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 239 "pwdadm.sqc"
      sqlasetdata(2,0,1,sql_setdlist,NULL,0L);
    }
#line 239 "pwdadm.sqc"
  sqlacall((unsigned short)24,3,2,0,0L);
#line 239 "pwdadm.sqc"
  sqlastop(0L);
}

#line 239 "pwdadm.sqc"


                switch( sqlca.sqlcode )
                {
 					case 100:
 					   printf( "\nUser does not exist.\n" );
 					   
/*
EXEC SQL ROLLBACK;
*/

{
#line 245 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 245 "pwdadm.sqc"
  sqlacall((unsigned short)28,0,0,0,0L);
#line 245 "pwdadm.sqc"
  sqlastop(0L);
}

#line 245 "pwdadm.sqc"

 					   break;
					default:
 					   printf( "\nAdmin flag removed.\n" );
 					   
/*
EXEC SQL COMMIT;
*/

{
#line 249 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 249 "pwdadm.sqc"
  sqlacall((unsigned short)21,0,0,0,0L);
#line 249 "pwdadm.sqc"
  sqlastop(0L);
}

#line 249 "pwdadm.sqc"

 					   break;
 				}

         		break;


             // List all users
             case 4:

   				
/*
EXEC SQL DECLARE c1 CURSOR FOR
				        SELECT usr, admin FROM pwdsafe.pwdlogin ORDER BY usr;
*/

#line 260 "pwdadm.sqc"


				
/*
EXEC SQL OPEN c1;
*/

{
#line 262 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 262 "pwdadm.sqc"
  sqlacall((unsigned short)26,4,0,0,0L);
#line 262 "pwdadm.sqc"
  sqlastop(0L);
}

#line 262 "pwdadm.sqc"

				EMB_SQL_CHECK("OPEN CURSOR");

				do {
				   
/*
EXEC SQL FETCH c1 INTO :username, :admin;
*/

{
#line 266 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 266 "pwdadm.sqc"
  sqlaaloc(3,2,6,0L);
    {
      struct sqla_setdata_list sql_setdlist[2];
#line 266 "pwdadm.sqc"
      sql_setdlist[0].sqltype = 460; sql_setdlist[0].sqllen = 32;
#line 266 "pwdadm.sqc"
      sql_setdlist[0].sqldata = (void*)username;
#line 266 "pwdadm.sqc"
      sql_setdlist[0].sqlind = 0L;
#line 266 "pwdadm.sqc"
      sql_setdlist[1].sqltype = 500; sql_setdlist[1].sqllen = 2;
#line 266 "pwdadm.sqc"
      sql_setdlist[1].sqldata = (void*)&admin;
#line 266 "pwdadm.sqc"
      sql_setdlist[1].sqlind = 0L;
#line 266 "pwdadm.sqc"
      sqlasetdata(3,0,2,sql_setdlist,NULL,0L);
    }
#line 266 "pwdadm.sqc"
  sqlacall((unsigned short)25,4,0,3,0L);
#line 266 "pwdadm.sqc"
  sqlastop(0L);
}

#line 266 "pwdadm.sqc"


				   if (SQLCODE != 0) break;

				   atext[0] = '\0';

				   if(admin != 0)
				   {
					   strcpy( atext, "yes" );
				   } else {
					   strcpy( atext, "no" );
				   }

				   printf( "\n%-32s Admin: %s", username, atext );

				} while ( 1 );

				
/*
EXEC SQL CLOSE c1;
*/

{
#line 283 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 283 "pwdadm.sqc"
  sqlacall((unsigned short)20,4,0,0,0L);
#line 283 "pwdadm.sqc"
  sqlastop(0L);
}

#line 283 "pwdadm.sqc"

                EMB_SQL_CHECK("CLOSE CURSOR");

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
#line 301 "pwdadm.sqc"
  sqlastrt(sqla_program_id, &sqla_rtinfo, &sqlca);
#line 301 "pwdadm.sqc"
  sqlacall((unsigned short)29,3,0,0,0L);
#line 301 "pwdadm.sqc"
  sqlastop(0L);
}

#line 301 "pwdadm.sqc"

   EMB_SQL_CHECK("CONNECT RESET");
   return 0;
}


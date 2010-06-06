/*
 * $Id$
 */

#ifdef __cplusplus
extern "C" {
#endif

int rc;
#define EMB_SQL_CHECK( MSG_STR )                               \
    rc = SqlInfoPrint( MSG_STR, &sqlca, __LINE__, __FILE__) ;  \
    if ( rc != 0 )                                             \
    {   TransRollback( );                                      \
        return 1;                                              \
    }		                                              

int  SqlInfoPrint( char *, struct sqlca *, int, char *);
void TransRollback( void);

#ifdef __cplusplus
}
#endif

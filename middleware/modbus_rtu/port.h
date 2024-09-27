#include <assert.h>
#include <stdint.h>
#include <stdbool.h>
#ifndef _PORT_H
#define _PORT_H



/* ----------------------- Defines ------------------------------------------*/
#define ENTER_CRITICAL_SECTION( ) vMBPortEnterCritical()
#define EXIT_CRITICAL_SECTION( ) vMBPortExitCritical()
#define MB_PORT_HAS_CLOSE   1
#ifndef TRUE
#define TRUE            1
#endif
#ifndef FALSE
#define FALSE           0
#endif
/* ----------------------- Type definitions ---------------------------------*/
    typedef enum
{
    MB_LOG_ERROR = 0,
    MB_LOG_WARN = 1,
    MB_LOG_INFO = 2,
    MB_LOG_DEBUG = 3
} eMBPortLogLevel;


/* ----------------------- Function prototypes ------------------------------*/

void            vMBPortEnterCritical( void );
void            vMBPortExitCritical( void );
void            vMBPortLog( eMBPortLogLevel eLevel, const int8_t * szModule,
                            const int8_t * szFmt, ... );
void            vMBPortTimerPoll(  );
bool            xMBPortSerialPoll(  );
bool            xMBPortSerialSetTimeout( uint16_t dwTimeoutMs );


#endif

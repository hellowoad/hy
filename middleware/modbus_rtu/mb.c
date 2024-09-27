
/* ----------------------- Platform includes --------------------------------*/
#include "port.h"

/* ----------------------- Modbus includes ----------------------------------*/
#include "./include/mb.h"
#include "./include/mbconfig.h"
#include "./include/mbframe.h"
#include "./include/mbproto.h"
#include "./include/mbfunc.h"

#include "./include/mbport.h"
#include "./rtu/mbrtu.h"


/* ----------------------- Static variables ---------------------------------*/

static uint8_t    ucMBAddress;
static eMBMode  eMBCurrentMode;

static enum
{
    STATE_ENABLED,
    STATE_DISABLED,
    STATE_NOT_INITIALIZED
} eMBState = STATE_NOT_INITIALIZED;

/* Functions pointer which are initialized in eMBInit( ). Depending on the
 * mode (RTU or ASCII) the are set to the correct implementations.
 */
static peMBFrameSend peMBFrameSendCur;
static peMBFrameReceive peMBFrameReceiveCur;

/* Callback functions required by the porting layer. They are called when
 * an external event has happend which includes a timeout or the reception
 * or transmission of a character.
 */
bool( *pxMBFrameCBByteReceived ) ( void );
bool( *pxMBFrameCBTransmitterEmpty ) ( void );

bool( *pxMBFrameCBReceiveFSMCur ) ( void );
bool( *pxMBFrameCBTransmitFSMCur ) ( void );

/* An array of Modbus functions handlers which associates Modbus function
 * codes with implementing functions.
 */
static xMBFunctionHandler xFuncHandlers[MB_FUNC_HANDLERS_MAX] = {

    {MB_FUNC_READ_INPUT_REGISTER, eMBFuncReadInputRegister},
    {MB_FUNC_READ_HOLDING_REGISTER, eMBFuncReadHoldingRegister},
    {MB_FUNC_WRITE_MULTIPLE_REGISTERS, eMBFuncWriteMultipleHoldingRegister},
    {MB_FUNC_WRITE_REGISTER, eMBFuncWriteHoldingRegister},
    {MB_FUNC_READ_COILS, eMBFuncReadCoils},
    {MB_FUNC_WRITE_SINGLE_COIL, eMBFuncWriteCoil},
    {MB_FUNC_WRITE_MULTIPLE_COILS, eMBFuncWriteMultipleCoils},
    {MB_FUNC_READ_DISCRETE_INPUTS, eMBFuncReadDiscreteInputs},
};

/* ----------------------- Start implementation -----------------------------*/

eMBErrorCode
eMBPoll( void )
{
    static uint8_t   *ucMBFrame;
    static uint8_t    ucRcvAddress;
    static uint8_t    ucFunctionCode;
    static uint16_t   usLength;
    static eMBException eException;

    int             i;
    eMBErrorCode    eStatus = MB_ENOERR;
    eMBEventType    eEvent;

    /* Check if there is a event available. If not return control to caller.
     * Otherwise we will handle the event. */
    if( !module_uart_queue_empty() )
    {
        eStatus = peMBFrameReceiveCur( &ucRcvAddress, &ucMBFrame, &usLength );
        if( eStatus == MB_ENOERR )
        {
            /* Check if the frame is for us. If not ignore the frame. */
            if( ( ucRcvAddress == ucMBAddress ) || ( ucRcvAddress == MB_ADDRESS_BROADCAST ) )
            {
                ucFunctionCode = ucMBFrame[MB_PDU_FUNC_OFF];
                eException = MB_EX_ILLEGAL_FUNCTION;
                for( i = 0; i < MB_FUNC_HANDLERS_MAX; i++ )
                {
                    /* No more function handlers registered. Abort. */
                    if( xFuncHandlers[i].ucFunctionCode == 0 )
                    {
                        break;
                    }
                    else if( xFuncHandlers[i].ucFunctionCode == ucFunctionCode )
                    {
                        eException = xFuncHandlers[i].pxHandler( ucMBFrame, &usLength );
                        break;
                    }
                }

                /* If the request was not sent to the broadcast address we
                * return a reply. */
                if( ucRcvAddress != MB_ADDRESS_BROADCAST )
                {
                    if( eException != MB_EX_NONE )
                    {
                        /* An exception occured. Build an error frame. */
                        usLength = 0;
                        ucMBFrame[usLength++] = ( uint8_t )( ucFunctionCode | MB_FUNC_ERROR );
                        ucMBFrame[usLength++] = eException;
                    }
             
                    eStatus = peMBFrameSendCur( ucMBAddress, ucMBFrame, usLength );
                }
            }
        }
        
    }
    return MB_ENOERR;
}

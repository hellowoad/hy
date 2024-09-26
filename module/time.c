#include "./time.h"
#include "bsp/time.h"

uint32_t module_time_get_clock()
{
    return bsp_time_get_clock();

}

void module_time_blockDelay_usec(uint32_t usec)
{
    bsp_time_blockDelay_usec(usec);
}

void module_time_blockDelay_msec(uint32_t msec)
{

    for(int i = 0; i< msec; i++)
    {
        module_time_blockDelay_usec(1000);
    }

}


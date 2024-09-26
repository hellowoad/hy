#include "bsp/time.h"

static uint32_t timerCount = 0;



uint32_t bspTime_get_clock()
{

    return timerCount;

}

void bspTime_blockDelay_usec(uint32_t usec)
{


}
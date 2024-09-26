#include <stdint.h>

#ifndef BSP_TIME_H
#define BSP_TIME_H

uint32_t bspTime_get_clock();
void bspTime_blockDelay_usec(uint32_t usec);

#endif
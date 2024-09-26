#include <stdint.h>

#ifndef BSP_RTC_H
#define BSP_RTC_H




struct Bsp_RTC_Time
{
    uint16_t year;
    uint16_t month;
    uint16_t day;
    uint16_t hour;
    uint16_t minute;
    uint16_t second;
};


uint16_t bsp_RTC_init();
uint16_t bsp_RTC_deinit();
uint16_t bsp_RTC_read(struct Bsp_RTC_Time *time);
uint16_t bsp_RTC_write(struct Bsp_RTC_Time *time);



#endif
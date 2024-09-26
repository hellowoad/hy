#include <stdint.h>
#include <stdbool.h>

#ifndef MODULE_RTC_H
#define MODULE_RTC_H

// real time
struct Module_RTC_Time
{
    uint16_t year;
    uint16_t month;
    uint16_t day;
    uint16_t hour;
    uint16_t minute;
    uint16_t second;
};

uint16_t module_RTC_init();
uint16_t module_RTC_deinit();
uint16_t module_RTC_get(struct Module_RTC_Time *real);
uint16_t module_RTC_refresh();
uint16_t module_RTC_calibration(struct Module_RTC_Time *cal);


#endif
#include "./rtc.h"
#include "bsp/time.h"
#include "bsp/rtc.h"

static struct Module_RTC_Time moduleRTCreal; 
static struct Module_RTC_Time moduleRTCcal;
static bool calRequest;

uint16_t module_RTC_init()
{
    bsp_RTC_init();
}
uint16_t module_RTC_deinit()
{
    bsp_RTC_deinit();
}

uint16_t module_RTC_get(struct Module_RTC_Time *real)
{    
    real->year = moduleRTCreal.year;
    real->month = moduleRTCreal.month;
    real->day = moduleRTCreal.day;
    real->hour = moduleRTCreal.hour;
    real->minute = moduleRTCreal.minute;
    real->second = moduleRTCreal.second;
}

uint16_t module_RTC_refresh()
{
    bsp_rtc_read(&moduleRTCreal);
    if(calRequest)
    {
        struct Bsp_RTC_Time time;
        time.year = moduleRTCcal.year;
        time.month = moduleRTCcal.month;
        time.day = moduleRTCcal.day;
        time.hour = moduleRTCcal.hour;
        time.minute = moduleRTCcal.minute;
        time.second = moduleRTCcal.second;
        bsp_rtc_write(&time);
        calRequest = false;
    }
}


uint16_t module_RTC_calibration(struct Module_RTC_Time *cal)
{
    calRequest = true;
    moduleRTCcal.year = cal->year;
    moduleRTCcal.month = cal->month;
    moduleRTCcal.day = cal->day;
    moduleRTCcal.hour = cal->hour;
    moduleRTCcal.minute = cal->minute;
    moduleRTCcal.second = cal->second;
}




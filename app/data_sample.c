
#include "module/rtc.h"


uint16_t app_RTC_refresh()
{

module_RTC_refresh();

}





uint16_t bms_data_refresh()
{
    
    watchDog_feed(2000);
    groupVol_refresh(100);
    groupCur_refresh(100);
    cellVol_refresh(100);
    cellTemp_refresh(100);
    envTemp_refresh(100);
    envBalanceTemp_refresh(100);
    envCurSampleTemp_refresh(100);
    alarm_refresh(100);
}


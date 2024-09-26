#include <stdlib.h>
#include "./data.h"
#include "common/util.h"

struct RegHold
{
    uint16_t regLen;
    struct RegHold *nextHold;
    void *data;
};

struct RegParaProjGrop
{    
    struct RegPara cellInitCap[16];
    struct RegPara packInitCap;
};

struct RegParaAlarmGrop
{    
    struct RegParaAlarm cellVol[3];
    struct RegParaAlarm packVol[3];
};


struct RegParaProjGrop regParaProjGrop = 
{
    .cellInitCap[0].addr = 1,   .cellInitCap[0].defaultValue = 100,     .cellInitCap[0].min = 0,    .cellInitCap[0].max = 100, .cellInitCap[0].permisss = 1,
    .packInitCap.addr = 17,     .packInitCap.defaultValue = 100,        .packInitCap.min = 50,      .packInitCap = 110,
    
};

struct RegParaAlarmGrop regParaAlarmGrop = 
{
    .cellVol[0].alarm.addr = 106,   .cellVol[0].alarm.defaultValue = 3550,      .cellVol[0].alarm.min = 2000,       .cellVol[0].alarm.max = 5000,       .cellVol[0].alarm.permisss = 1,
    .cellVol[0].restore.addr = 106, .cellVol[0].restore.defaultValue = 3550,    .cellVol[0].restore.min = 2000,     .cellVol[0].restore.max = 5000,     .cellVol[0].restore.permisss = 1,
    .cellVol[0].delay = 5000,

    .cellVol[1].alarm.addr = 106,   .cellVol[1].alarm.defaultValue = 3550,      .cellVol[1].alarm.min = 2000,       .cellVol[1].alarm.max = 5000,       .cellVol[1].alarm.permisss = 1,
    .cellVol[1].restore.addr = 106, .cellVol[1].restore.defaultValue = 3550,    .cellVol[1].restore.min = 2000,     .cellVol[1].restore.max = 5000,     .cellVol[1].restore.permisss = 1,
    .cellVol[1].delay = 5000,

    .cellVol[2].alarm.addr = 106,   .cellVol[2].alarm.defaultValue = 3550,      .cellVol[2].alarm.min = 2000,       .cellVol[2].alarm.max = 5000,       .cellVol[2].alarm.permisss = 1,
    .cellVol[2].restore.addr = 106, .cellVol[2].restore.defaultValue = 3550,    .cellVol[2].restore.min = 2000,     .cellVol[2].restore.max = 5000,     .cellVol[2].restore.permisss = 1,
    .cellVol[2].delay = 5000,
};

struct RegHold projPara = {2,NULL,&regParaProjGrop};
struct RegHold alarmPara = {2,NULL,&regParaAlarmGrop};




bool project_para_valid(uint16_t addr, uint16_t value)
{
    for(int i = 0; i < regParaProj.paraProjLen; i++){
        
    }
}


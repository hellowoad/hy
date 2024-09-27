#include <stdlib.h>
#include "./data.h"
#include "common/util.h"


struct ParaProj
{    
    struct RegPara cellInitCap[16];
    struct RegPara packInitCap;
};

struct BMS_Alarm
{    
    struct ParaAlarm cellVol[3];
    struct ParaAlarm packVol[3];
};


struct ParaProj paraProj = 
{
    .cellInitCap[0].addr = 1,   .cellInitCap[0].defaultValue = 100,     .cellInitCap[0].min = 0,    .cellInitCap[0].max = 100, .cellInitCap[0].permisss = 1,
    .packInitCap.addr = 17,     .packInitCap.defaultValue = 100,        .packInitCap.min = 50,      .packInitCap = 110,
    
};

struct BMS_Alarm BMSalarm = 
{
    .cellVol[0].alarm.addr = 106,   .cellVol[0].alarm.defaultValue = 3550,      .cellVol[0].alarm.min = 2000,       .cellVol[0].alarm.max = 5000,       .cellVol[0].alarm.permisss = 1,
    .cellVol[0].restore.addr = 106, .cellVol[0].restore.defaultValue = 3550,    .cellVol[0].restore.min = 2000,     .cellVol[0].restore.max = 5000,     .cellVol[0].restore.permisss = 1,
    .cellVol[0].delay.addr = 106,   .cellVol[0].delay.defaultValue = 5000,      .cellVol[0].delay.min = 100,        .cellVol[0].delay.max= 60000,       .cellVol[0].delay.permisss = 1,

    .cellVol[1].alarm.addr = 106,   .cellVol[1].alarm.defaultValue = 3550,      .cellVol[1].alarm.min = 2000,       .cellVol[1].alarm.max = 5000,       .cellVol[1].alarm.permisss = 1,
    .cellVol[1].restore.addr = 106, .cellVol[1].restore.defaultValue = 3550,    .cellVol[1].restore.min = 2000,     .cellVol[1].restore.max = 5000,     .cellVol[1].restore.permisss = 1,
    .cellVol[1].delay.addr = 106,   .cellVol[1].delay.defaultValue = 5000,      .cellVol[1].delay.min = 100,        .cellVol[1].delay.max= 60000,       .cellVol[1].delay.permisss = 1,

    .cellVol[2].alarm.addr = 106,   .cellVol[2].alarm.defaultValue = 3550,      .cellVol[2].alarm.min = 2000,       .cellVol[2].alarm.max = 5000,       .cellVol[2].alarm.permisss = 1,
    .cellVol[2].restore.addr = 106, .cellVol[2].restore.defaultValue = 3550,    .cellVol[2].restore.min = 2000,     .cellVol[2].restore.max = 5000,     .cellVol[2].restore.permisss = 1,
    .cellVol[2].delay.addr = 106,   .cellVol[2].delay.defaultValue = 5000,      .cellVol[2].delay.min = 100,        .cellVol[2].delay.max= 60000,       .cellVol[2].delay.permisss = 1,
};



bool project_para_valid(uint16_t addr, uint16_t value)
{
    for(int i = 0; i < sizeof(struct ParaAlarm)/sizeof(struct RegPara); i++){
        
    }
}


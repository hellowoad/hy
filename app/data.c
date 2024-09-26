#include <stdlib.h>
#include "./data.h"
#include "common/util.h"

struct RegHold
{
    uint16_t regLen;
    struct RegHold *nextHold;
    void *data;
};

struct RegParaProj
{    
    struct RegPara cellInitCap[16];
    struct RegPara packInitCap;
};

struct RegParaProj regParaProj = 
{
    .cellInitCap[0].addr = 1,   .cellInitCap[0].defaultValue = 100,     .cellInitCap[0].min = 0,    .cellInitCap[0].max = 100, .cellInitCap[0].permisss = 1,
    .packInitCap.addr = 17,     .packInitCap.defaultValue = 100,        .packInitCap.min = 50,      .packInitCap = 110,
    
};

struct RegHold projPara = {2,NULL,&regParaProj};




bool project_para_valid(uint16_t addr, uint16_t value)
{
    for(int i = 0; i < regParaProj.paraProjLen; i++){
        
    }
}


#include <stdint.h>
#include <stdbool.h>

#ifndef APP_DATA_H
#define APP_DATA_H

struct RegPara
{
    uint16_t addr;
    #define _TYPE uint16_t
    _TYPE value;
    _TYPE defaultValue;
    _TYPE min;
    _TYPE max;
    #undef _TYPE
    uint8_t permisss;
};

struct RegData
{
    uint16_t addr;
    #define _TYPE uint16_t
    _TYPE value;
    #undef _TYPE
};

struct RegCtrl
{
    uint16_t addr;
    bool act;
    #define _TYPE uint16_t
    _TYPE actValue;
    #undef _TYPE

};



#define PROJECT_PARA_LEN    30






#endif
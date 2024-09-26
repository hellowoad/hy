#include "app.h"
#include "common/util.h"

struct CycleNode
{
    void *fn;
    int cycle;
    int clock;
};


struct CycleNode cycleNodeAry[CYCLE_NODE_NUM];

int cycle_register(void *fun){


}

int cycle_Run(void *fn, int msec)
{

}
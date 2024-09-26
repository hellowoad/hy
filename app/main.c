#include "module/rtc.h"

uint16_t hardware_init()
{
    module_RTC_init();

}

uint16_t software_init()
{


}


int main(void){

    hardware_init();
    software_init();

    while(1){
        //communicate
        com_uart();
        // bms data refresh

        // strategy
        run_strategy(100);
        cell_balance_strategy(100);
        sox_strategy(1000);
        cell_warm_strategy(100);
        auxPower_control_strategy(100);
    }
    
}






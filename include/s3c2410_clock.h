#include "S3C2410.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t LOCKTIME; // 0x4c000000 PLL lock time count
        __IO uint32_t MPLLCON;  // 0x4c000004 MPLL cfg
        __IO uint32_t UPLLCON;  // 0x4c000008 UPLL cfg
        __IO uint32_t CLKCON;   // 0x4c00000c Clock generator control
        __IO uint32_t CLKSLOW;  // 0x4c000010 Slow clock control
        __IO uint32_t CLKDIVN;  // 0x4c000014 Clock divider control
    } ClockTypeDef;

#define SYSCLOCK ((ClockTypeDef *)CLOCK_BASE)

#ifdef __cplusplus
}
#endif
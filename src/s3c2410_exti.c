#include "s3c2410_exti.h"

void EXTI_SetTriggerMode(uint8_t nEXTI, EXTI_TriggerMode mode, FuncState filter)
{
    __IO uint32_t *rEXTICFG;
    if (nEXTI < 8)
        rEXTICFG = &(EXTI->EXTINT0);
    else if (nEXTI < 16)
    {
        rEXTICFG = &(EXTI->EXTINT1);
        nEXTI -= 8;
    }
    else if (nEXTI < 24)
    {
        rEXTICFG = &(EXTI->EXTINT2);
        nEXTI -= 16;

        // FLTEN is only available for EINT16-23
        *rEXTICFG &= ~(1 << ((nEXTI << 2) | 3));   // Clear the FLTEN bit
        *rEXTICFG |= filter << ((nEXTI << 2) | 3); // Set the FLTEN bit
    }
    else
        return;

    *rEXTICFG &= ~(7 << (nEXTI << 2)); // Clear the trigger mode bits
    *rEXTICFG |= mode << (nEXTI << 2); // Set the mode
}

void EXTI_ConfigFilter(uint8_t nEXTI, EXTI_FilterClock clock, uint8_t filterWidth)
{
    if (nEXTI < 16)
        return;
    if (nEXTI > 23)
        return;

    __IO uint32_t *rFLT;
    if (nEXTI < 20)
    {
        rFLT = &(EXTI->EINTFLT2);
        nEXTI -= 16;
    }
    else
    {
        rFLT = &(EXTI->EINTFLT3);
        nEXTI -= 20;
    }

    *rFLT &= ~(0xff << (nEXTI << 3));                      // Clear the filter bits
    *rFLT |= ((clock << 7) | filterWidth) << (nEXTI << 3); // Set the filter bits
}

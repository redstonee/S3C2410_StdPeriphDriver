#pragma once

#include "S3C2410.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t EXTINT0;  // 0x88 Trigger Mode for EINT0-7
        __IO uint32_t EXTINT1;  // 0x8C Trigger Mode for EINT7-15
        __IO uint32_t EXTINT2;  // 0x90 Trigger Mode for EINT16-23
        __IO uint32_t EINTFLT0; // 0x94 Reserved
        __IO uint32_t EINTFLT1; // 0x98 Reserved
        __IO uint32_t EINTFLT2; // 0x9C Filter Control for EINT16-19
        __IO uint32_t EINTFLT3; // 0xA0 Filter Control for EINT20-23
        __IO uint32_t EINTMASK; // 0xA4 Mask for EINT4-23
        __IO uint32_t EINTPEND; // 0xA8 Pending for EINT4-23
    } EXTI_TypeDef;

#define EXTI ((EXTI_TypeDef *)EXTI_BASE)

    typedef enum
    {
        EXTI_LOW_LEVEL = 0,
        EXTI_HIGH_LEVEL = 1,
        EXTI_FALLING_EDGE = 2,
        EXTI_RISING_EDGE = 4,
        EXTI_BOTH_EDGE = 6,
    } EXTI_TriggerMode;

    typedef enum
    {
        PCLK = 0,
        EXTCLK = 1,
    } EXTI_FilterClock;

    void EXTI_SetTriggerMode(uint8_t nEXTI, EXTI_TriggerMode mode, FuncState filter);
    void EXTI_ConfigFilter(uint8_t nEXTI, EXTI_FilterClock clock, uint8_t filterWidth);

#define EXTI_Enable(nEXIT) (EXTI->EINTMASK &= ~(1 << nEXIT))
#define EXTI_Disable(nEXIT) (EXTI->EINTMASK |= (1 << nEXIT))
#define EXTI_GetPending(nEXTI) ((EXTI->EINTPEND & (1 << nEXTI)) ? 1 : 0)
#define EXTI_ClearPending(nEXTI) (EXTI->EINTPEND |= (1 << nEXTI))

#ifdef __cplusplus
}
#endif
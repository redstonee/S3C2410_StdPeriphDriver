#pragma once

#include "S3C2410.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t SRCPND;    // 0x00 Source pending
        __IO uint32_t INTMOD;    // 0x04 Interrupt mode
        __IO uint32_t INTMSK;    // 0x08 Interrupt mask, default 0xFFFFFFFF
        __IO uint32_t PRIORITY;  // 0x0C IRQ priority, default 0x0
        __IO uint32_t INTPND;    // 0x10 Interrupt pending (IQQ)
        __IO uint32_t INTOFFSET; // 0x14 Interrupt offset (IRQ)
        __IO uint32_t SUBSRCPND; // 0x18 Sub-source pending
        __IO uint32_t INTSUBMSK; // 0x2C Interrupt sub-mask
    } INT_TypeDef;

#define Interrupt ((INT_TypeDef *)INT_BASE)

    typedef enum
    {
        SRC_EINT0 = 1 << 0,
        SRC_EINT1 = 1 << 1,
        SRC_EINT2 = 1 << 2,
        SRC_EINT3 = 1 << 3,
        SRC_EINT4_7 = 1 << 4,
        SRC_EINT8_13 = 1 << 5,

        SRC_BATT_FTL = 1 << 7,
        SRC_INT_TICK = 1 << 8,
        SRC_INT_WDT = 1 << 9,
        SRC_INT_TIM0 = 1 << 10,
        SRC_INT_TIM1 = 1 << 11,
        SRC_INT_TIM2 = 1 << 12,
        SRC_INT_TIM3 = 1 << 13,
        SRC_INT_TIM4 = 1 << 14,
        SRC_INT_UART2 = 1 << 15,
        SRC_INT_LCD = 1 << 16,
        SRC_INT_DMA0 = 1 << 17,
        SRC_INT_DMA1 = 1 << 18,
        SRC_INT_DMA2 = 1 << 19,
        SRC_INT_DMA3 = 1 << 20,
        SRC_INT_SDI = 1 << 21,
        SRC_INT_SPI9 = 1 << 22,
        SRC_INT_UART1 = 1 << 23,

        SRC_INT_USBD = 1 << 25,
        SRC_INT_USBH = 1 << 26,
        SRC_INT_I2C = 1 << 27,
        SRC_INT_UART0 = 1 << 28,
        SRC_INT_SPI1 = 1 << 29,
        SRC_INT_RTC = 1 << 30,
        SRC_INT_ADC = 1 << 31,
    } InterruptSource;

    typedef enum
    {
        SUBSRC_INT_RXD0 = 1,
        SUBSRC_INT_TXD0 = 1 << 1,
        SUBSRC_INT_ERR0 = 1 << 2,
        SUBSRC_INT_RXD1 = 1 << 3,
        SUBSRC_INT_TXD1 = 1 << 4,
        SUBSRC_INT_ERR1 = 1 << 5,
        SUBSRC_INT_RXD2 = 1 << 6,
        SUBSRC_INT_TXD2 = 1 << 7,
        SUBSRC_INT_ERR2 = 1 << 8,
        SUBSRC_INT_TC = 1 << 9,
        SUBSRC_INT_ADC = 1 << 10,
    } SubInterruptource;

    typedef enum
    {
        MODE_IRQ = 0,
        MODE_FIQ = 1
    } InterruptMode;

// Set whether IRQ(0) or FIQ(1), default is IRQ
#define INT_SetMode(src, mode) (mode ? (Interrupt->INTMOD |= src) : (Interrupt->INTMOD &= (~src)))

#define INT_Enable(src) (Interrupt->INTMSK &= (~src))
#define INT_Disable(src) (Interrupt->INTMSK |= src)

#define INT_EnableSub(subsrc) (Interrupt->SUBINTMSK &= (~subsrc))
#define INT_DisableSub(subsrc) (Interrupt->SUBINTMSK |= subsrc)

#define INT_GetSourcePending(src) (Interrupt->SRCPND & src != 0)
#define INT_GetInterruptPending(src) ((Interrupt->INTPND & src) != 0)

// Write 1 to clear, which is fucking weired
#define INT_ClearInterruptPending() (Interrupt->INTPND = Interrupt->INTPND) // Only 1 bit will be set at a time
#define INT_ClearSourcePending(src) (Interrupt->SRCPND |= src)

#define INT_GetSubSourcePending(subsrc) ((Interrupt->SUBSRCPND & subsrc == 0) ? 0 : 1)
#define INT_ClearSubSourcePending(subsrc) (Interrupt->SUBSRCPND |= subsrc)

#ifdef __cplusplus
}
#endif
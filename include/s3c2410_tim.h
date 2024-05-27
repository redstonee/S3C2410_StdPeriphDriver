#pragma once

#include <S3C2410.h>

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t TCFG0; // 0x00 Timer prescalers configuration
        __IO uint32_t TCFG1; // 0x04 Timer MUX/DMA configuration
        __IO uint32_t TCON;  // 0x08 Timer control
    } TIM_CFG_TypeDef;

    typedef struct
    {
        __IO uint32_t TCNTB; // 0x00 Timer count buffer
        __IO uint32_t TCMPB; // 0x04 Timer compare buffer
        __IO uint32_t TCNTO; // 0x08 Timer count observation
    } TIM_0_3_TypeDef;

    typedef struct
    {
        __IO uint32_t TCNTB; // 0x00 Timer count buffer
        __IO uint32_t TCNTO; // 0x04 Timer count observation
    } TIM_4_TypeDef;

#define TIM_CFG ((TIM_CFG_TypeDef *)TIM_CFG_BASE)
#define TIM0 ((TIM_0_3_TypeDef *)TIM0_BASE)
#define TIM1 ((TIM_0_3_TypeDef *)TIM1_BASE)
#define TIM2 ((TIM_0_3_TypeDef *)TIM2_BASE)
#define TIM3 ((TIM_0_3_TypeDef *)TIM3_BASE)
#define TIM4 ((TIM_4_TypeDef *)TIM4_BASE)

    typedef enum
    {
        TIM_MUX_Input_1_2 = 0,
        TIM_MUX_Input_1_4,
        TIM_MUX_Input_1_8,
        TIM_MUX_Input_1_16,
        TIM_MUX_Input_TCLK
    } TIM_MUX_Input;

    typedef enum
    {
        TIM_DMA_Channel_All = 0,
        TIM_DMA_Channel_0,
        TIM_DMA_Channel_1,
        TIM_DMA_Channel_2,
        TIM_DMA_Channel_3,
        TIM_DMA_Channel_4
    } TIM_DMA_Channel;

    // Set the prescaler for timer 0 and 1
    void TIM_SetPrescaler0(uint8_t prescaler);

    // Set the prescaler for timer 2, 3 and 4
    void TIM_SetPrescaler1(uint8_t prescaler);

    // Set the dead zone for timer 0
    void TIM_SetDeadZone(uint8_t deadZone);

    // Set the input for a timer
    void TIM_SetInput(uint8_t nTimer, TIM_MUX_Input input);

    // Set the timer DMA mode
    void TIM_SetDMARequestChannel(TIM_DMA_Channel channel);

    // Set Start/Stop for a timer
    void TIM_SetStart(uint8_t nTimer, FuncState start);

    // Set Auto-Reload for a timer
    void TIM_SetAutoReload(uint8_t nTimer, FuncState autoReload);

    // Set Output Inverter for a timer
    void TIM_SetOutputInverter(uint8_t nTimer, FuncState outputInverter);

    // Set manual update for a timer
    void TIM_ManualUpdate(uint8_t nTimer);

    // Set state of the dead zone for timer 0
#define TIM0_SetDeadZoneState(status) (status ? (TIM_CFG->TCON |= (1 << 4)) : (TIM_CFG->TCON &= ~(1 << 4)))

#define TIM_SetCountBuffer(timer, count) (timer->TCNTB = count & 0xffff)
#define TIM_SetCompareBuffer(timer, count) (timer->TCMPB = count & 0xffff)

#define TIM_GetCountBuffer(timer) (uint16_t)(timer->TCNTB & 0xffff)
#define TIM_GetCompareBuffer(timer) (uint16_t)(timer->TCMPB & 0xffff)
#define TIM_GetCountObservation(timer) (uint16_t)(timer->TCNTO & 0xffff)

#ifdef __cplusplus
}
#endif
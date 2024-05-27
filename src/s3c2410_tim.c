#include "s3c2410_tim.h"

// Set the prescaler for timer 0 and 1
void TIM_SetPrescaler0(uint8_t prescaler)
{
    TIM_CFG->TCFG0 &= ~(0xff);   // Clear the prescaler bits
    TIM_CFG->TCFG0 |= prescaler; // Set the prescaler bits
}

// Set the prescaler for timer 2, 3 and 4
void TIM_SetPrescaler1(uint8_t prescaler)
{
    TIM_CFG->TCFG0 &= ~(0xff00);      // Clear the prescaler bits
    TIM_CFG->TCFG0 |= prescaler << 8; // Set the prescaler bits
}

// Set the dead zone for timer 0
void TIM_SetDeadZone(uint8_t deadZone)
{
    TIM_CFG->TCFG0 &= ~(0xff0000);                // Clear the dead zone bits
    TIM_CFG->TCFG0 |= (uint32_t)(deadZone << 16); // Set the dead zone bits
}

// Set the input for a timer
void TIM_SetInput(uint8_t nTimer, TIM_MUX_Input input)
{
    if (nTimer > 4)
        return;
    TIM_CFG->TCFG1 &= ~(0x7 << (nTimer << 2)); // Clear the input bits
    TIM_CFG->TCFG1 |= input << (nTimer << 2);  // Set the input bits
}

// Set the timer DMA mode
void TIM_SetDMARequestChannel(TIM_DMA_Channel channel)
{
    TIM_CFG->TCFG1 &= ~(0xff << 20); // Clear the DMA bits
    TIM_CFG->TCFG1 |= channel << 20; // Set the DMA bits
}

void TCON_SetBit(uint8_t nTimer, uint8_t bitOffset, FuncState bit)
{
    if (nTimer > 4) // Invalid timer
        return;
    if (nTimer > 0)                                // Timer 1-4
        bitOffset = (nTimer << 2) + 4 + bitOffset; // n * 4 + 4 + bitOffset

    if (bit)
        TIM_CFG->TCON |= 1 << bitOffset;
    else
        TIM_CFG->TCON &= ~(1 << bitOffset);
}

// Set Start/Stop for a timer
void TIM_SetStart(uint8_t nTimer, FuncState start)
{
    TCON_SetBit(nTimer, 0, start);
}

// Update settings for a timer
void TIM_ManualUpdate(uint8_t nTimer)
{
    TCON_SetBit(nTimer, 1, 1);
    TCON_SetBit(nTimer, 1, 0);
}

// Set Output Inverter for a timer
void TIM_SetOutputInverter(uint8_t nTimer, FuncState outputInverter)
{
    TCON_SetBit(nTimer, 2, outputInverter);
}

// Set Auto-Reload for a timer
void TIM_SetAutoReload(uint8_t nTimer, FuncState autoReload)
{
    if (nTimer == 4)
        TCON_SetBit(nTimer, 2, autoReload);
    else
        TCON_SetBit(nTimer, 3, autoReload);
}

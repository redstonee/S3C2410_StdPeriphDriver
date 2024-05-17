#pragma once

#include "S3C2410.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct
    {
        __IO uint32_t BWSCON;   // 0x00
        __IO uint32_t BANKCON0; // 0x04
        __IO uint32_t BANKCON1;
        __IO uint32_t BANKCON2;
        __IO uint32_t BANKCON3;
        __IO uint32_t BANKCON4;
        __IO uint32_t BANKCON5;
        __IO uint32_t BANKCON6;
        __IO uint32_t BANKCON7;
        __IO uint32_t REFRESH;
        __IO uint32_t BANKSIZE; // 0x28
    } MemCtl_TypeDef;

#define MEM_CTL ((Mem_Ctl_TypeDef *)MEM_CTL_BASE)

    typedef enum
    {
        BusWidth_8b = 0,
        BusWidth_16b,
        BusWidth_32b,

    } DataBusWidth;

    typedef enum
    {
        SetUpHoldTime_0 = 0, // 0 clock
        SetUpHoldTime_1,
        SetUpHoldTime_2,
        SetUpHoldTime_4, // 4 clocks
    } SetUpHoldTime;

    typedef enum
    {
        AccessCycle_1 = 0, // 0 clock
        AccessCycle_2,
        AccessCycle_3,
        AccessCycle_4,
        AccessCycle_6,
        AccessCycle_8,
        AccessCycle_10,
        AccessCycle_14 // 14 clock
    } AccessCycle;

    typedef enum
    {
        PageModeAccessCycle_2 = 0, // 2 clocks
        PageModeAccessCycle_3,
        PageModeAccessCycle_4,
        PageModeAccessCycle_6, // 6 clocks
    } PageModeAccessCycle;

    typedef enum
    {
        PageMode_1 = 0, // 1 data
        PageMode_4,
        PageMode_8,
        PageMode_16 // 16 data
    } PageModeCfg;

    typedef enum
    {
        MemoryType_SROM = 0,  // SRAM or ROM
        MemoryType_SDRAM = 0, // SDRAM
    } MemoryType;

    typedef enum
    {
        AutoRefresh = 0,
        SelfRefresh = 0,
    } RefreshMode;

    typedef enum
    {
        PreChargeTime_2 = 0, // 2 clocks
        PreChargeTime_3,
        PreChargeTime_4
    } PreChargeTime;

    typedef enum
    {
        RasToCasDelay_2 = 0, // 2 clocks
        RasToCasDelay_3,
        RasToCasDelay_4,
    } RasToCasDelay;

    typedef enum
    {
        ColAddrNum_8 = 0, // 8-bit
        ColAddrNum_9,
        ColAddrNum_10,
    } ColAddrNum;

    typedef enum
    {
        SemiRowCycle_4 = 0, // 4 clocks
        SemiRowCycle_5,
        SemiRowCycle_6,
        SemiRowCycle_7
    } SemiRowTime;

    typedef enum
    {
        AlwaysActive = 0,
        ActiveDuringAccess,
    } SCLK_EN;

    typedef enum
    {
        MemoryMap_32M = 0,
        MemoryMap_64M,
        MemoryMap_128M,
        MemoryMap_2M = 4,
        MemoryMap_4M,
        MemoryMap_8M,
        MemoryMap_16M,
    } MemoryMap;

    typedef enum
    {
        CasLatency_1 = 0,
        CasLatency_2,
        CasLatency_3,
    } CasLatency;

    struct Bank0to5
    {
        FuncState Using_UB_LB;
        FuncState Wait;
        DataBusWidth BusWidth;
        SetUpHoldTime Tacs;
        SetUpHoldTime Tcos;
        AccessCycle Tacc;
        SetUpHoldTime Tcoh;
        SetUpHoldTime Tcah;
        PageModeAccessCycle Tacp;
        PageModeCfg PMC;
    };

    struct Bank67
    {
        FuncState Using_UB_LB;
        FuncState Wait;
        DataBusWidth BusWidth;

        MemoryType type;
    };

    typedef struct
    {
        Bank67 bank6;
        Bank67 bank7;

    } MemCtl_Init_TypeDef;

#ifdef __cplusplus
}
#endif
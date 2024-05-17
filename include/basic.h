#ifndef __BASIC_H__
#define __BASIC_H__

/*-----------------------------------------------------------------------------*/
/* Including Files											                     		     */
/*-----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

/*!
 *\name IO definitions
 *\brief define access restrictions to peripheral registers
 *\{
 */
#ifndef __I
#define __I volatile const /*!< defines 'read only' permissions      */
#endif
#ifndef __O
#define __O volatile /*!< defines 'write only' permissions     */
#endif
#ifndef __IO
#define __IO volatile /*!< defines 'read / write' permissions   */
#endif
/**\}*/

/*-----------------------------------------------------------------------------*/
/* Types Declarations       	                                              						     */
/*-----------------------------------------------------------------------------*/
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef unsigned long long UINT64;
typedef char INT8;
typedef short INT16;
typedef int INT32;
typedef long LONG32;
typedef float FLOAT32;
typedef double FLOAT64;

typedef signed long long s64;
typedef unsigned long long u64;
typedef int32_t s32;
typedef int16_t s16;
typedef int8_t s8;

typedef const int32_t sc32; /*!< Read Only */
typedef const int16_t sc16; /*!< Read Only */
typedef const int8_t sc8;   /*!< Read Only */

typedef __IO int32_t vs32;
typedef __IO int16_t vs16;
typedef __IO int8_t vs8;

typedef __I int32_t vsc32; /*!< Read Only */
typedef __I int16_t vsc16; /*!< Read Only */
typedef __I int8_t vsc8;   /*!< Read Only */

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef const uint32_t uc32; /*!< Read Only */
typedef const uint16_t uc16; /*!< Read Only */
typedef const uint8_t uc8;   /*!< Read Only */

/*-----------------------------------------------------------------------------*/
/*  Constant Definitions														   */
/*-----------------------------------------------------------------------------*/

#define REG8(x) (*(volatile UINT8 *)(x))
#define REG16(x) (*(volatile UINT16 *)(x))
#define REG32(x) (*(volatile UINT32 *)(x))
#define REG64(x) (*(volatile UINT64 *)(x))

#define SREG8(x) (*(volatile INT8 *)(x))
#define SREG16(x) (*(volatile INT16 *)(x))
#define SREG32(x) (*(volatile INT32 *)(x))
#define SREG64(x) (*(volatile INT64 *)(x))

// typedef void (*const vect_t)(void) __irq;

#define TRUE (1)
#define FALSE (0)

typedef enum
{
    DISABLE = 0,
    ENABLE = 1
} FuncState;

#define BIT0 ((u32)0x01)
#define BIT1 ((u32)0x02)
#define BIT2 ((u32)0x04)
#define BIT3 ((u32)0x08)
#define BIT4 ((u32)0x10)
#define BIT5 ((u32)0x20)
#define BIT6 ((u32)0x40)
#define BIT7 ((u32)0x80)
#define BIT8 ((u32)0x0100)
#define BIT9 ((u32)0x0200)
#define BIT10 ((u32)0x0400)
#define BIT11 ((u32)0x0800)
#define BIT12 ((u32)0x1000)
#define BIT13 ((u32)0x2000)
#define BIT14 ((u32)0x4000)
#define BIT15 ((u32)0x8000)
#define BIT16 ((u32)0x10000)
#define BIT17 ((u32)0x20000)
#define BIT18 ((u32)0x40000)
#define BIT19 ((u32)0x80000)
#define BIT20 ((u32)0x100000)
#define BIT21 ((u32)0x200000)
#define BIT22 ((u32)0x400000)
#define BIT23 ((u32)0x800000)
#define BIT24 ((u32)0x1000000)
#define BIT25 ((u32)0x2000000)
#define BIT26 ((u32)0x4000000)
#define BIT27 ((u32)0x8000000)
#define BIT28 ((u32)0x10000000)
#define BIT29 ((u32)0x20000000)
#define BIT30 ((u32)0x40000000)
#define BIT31 ((u32)0x80000000)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif //_BASIC_H_

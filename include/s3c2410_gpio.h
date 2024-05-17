#pragma once

#include "S3C2410.h"

#ifdef __cplusplus
extern "C"
{
#endif // __cplusplus

    typedef struct
    {
        __IO uint32_t CON; /*!< 0x00 Configuration register  */
        __IO uint32_t DAT; /*!< 0x04 Data register */
    } GPIOA_TypeDef;

    typedef struct
    {
        __IO uint32_t CON; /*!< 0x00 Configuration register  */
        __IO uint32_t DAT; /*!< 0x04 Data register */
        __IO uint32_t UP;  /*!< 0x08 Pull-up control register*/
    } GPIO_TypeDef;

#define GPIOA ((GPIOA_TypeDef *)GPIOA_BASE)
#define GPIOB ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH ((GPIO_TypeDef *)GPIOH_BASE)

    typedef enum
    {
        GPIO_Mode_IN = 0x00,  /*!< GPIO input */
        GPIO_Mode_OUT = 0x01, /*!< GPIO output */
        GPIO_Mode_AF1 = 0x02, /*!< GPIO alternate function 1 */
        GPIO_Mode_AF2 = 0x03, /*!< GPIO alternate function 2 */
    } GPIOMode_TypeDef;

    typedef enum
    {
        GPIO_PullUp = 0x00,   /*!< GPIO pull-up */
        GPIO_NoPullUp = 0x01, /*!< GPIO no pull-up */
    } GPIOPullUp_TypeDef;

    typedef enum
    {
        Bit_RESET = 0,
        Bit_SET
    } BitAction;

    typedef struct
    {
        uint32_t GPIO_Pin;              /*!< GPIO pin */
        GPIOMode_TypeDef GPIO_Mode;     /*!< GPIO mode */
        GPIOPullUp_TypeDef GPIO_PullUp; /*!< GPIO pull-up */

    } GPIO_InitTypeDef;

#define GPIO_Pin_0 ((uint32_t)0x0001)
#define GPIO_Pin_1 ((uint32_t)0x0002)
#define GPIO_Pin_2 ((uint32_t)0x0004)
#define GPIO_Pin_3 ((uint32_t)0x0008)
#define GPIO_Pin_4 ((uint32_t)0x0010)
#define GPIO_Pin_5 ((uint32_t)0x0020)
#define GPIO_Pin_6 ((uint32_t)0x0040)
#define GPIO_Pin_7 ((uint32_t)0x0080)
#define GPIO_Pin_8 ((uint32_t)0x0100)
#define GPIO_Pin_9 ((uint32_t)0x0200)
#define GPIO_Pin_10 ((uint32_t)0x0400)
#define GPIO_Pin_11 ((uint32_t)0x0800)
#define GPIO_Pin_12 ((uint32_t)0x1000)
#define GPIO_Pin_13 ((uint32_t)0x2000)
#define GPIO_Pin_14 ((uint32_t)0x4000)
#define GPIO_Pin_15 ((uint32_t)0x8000)

    void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct);
    void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct);

#define GPIO_Write(GPIOx, Val) ((GPIOx)->DAT = (Val))
#define GPIO_Read(GPIOx) ((GPIOx)->DAT)

#define GPIO_WriteBits(GPIOx, GPIO_Pin, BitVal) ((BitVal) ? ((GPIOx)->DAT |= (GPIO_Pin)) : ((GPIOx)->DAT &= ~(GPIO_Pin)))
#define GPIO_ReadBit(GPIOx, GPIO_Pin) ((GPIOx)->DAT & (GPIO_Pin) ? Bit_SET : Bit_RESET)
#define GPIO_ToggleBits(GPIOx, GPIO_Pin) ((GPIOx)->DAT ^= (GPIO_Pin))

#ifdef __cplusplus
}
#endif

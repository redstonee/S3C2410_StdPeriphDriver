#include "s3c2410_gpio.h"

void GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_InitStruct)
{
    uint32_t pinpos = 0x00, pos = 0x00, currentpin = 0x00;

    /*------------------------- GPIO Mode Configuration ---------------------*/
    for (pinpos = 0x00; pinpos < 0x10; pinpos++)
    {
        pos = ((uint32_t)0x01) << pinpos;
        /* Get the port pins position */
        currentpin = (GPIO_InitStruct->GPIO_Pin) & pos;

        if (currentpin == pos)
        {
            GPIOx->CON &= ~(0x3 << (pinpos << 1));
            GPIOx->CON |= (GPIO_InitStruct->GPIO_Mode << (pinpos << 1));
        }
    }
}

void GPIO_StructInit(GPIO_InitTypeDef *GPIO_InitStruct)
{
    /* Reset GPIO init structure parameters values */
    GPIO_InitStruct->GPIO_Pin = GPIO_Pin_0;
    GPIO_InitStruct->GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStruct->GPIO_PullUp = GPIO_NoPullUp;
}

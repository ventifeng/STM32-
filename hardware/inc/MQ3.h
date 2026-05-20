#ifndef __MQ3_H
#define __MQ3_H
#include "stm32f10x.h"

// MQ3传感器引脚定义
#define MQ3_PORT GPIOA
#define MQ3_PIN GPIO_Pin_1
#define MQ3_RCC RCC_APB2Periph_GPIOA

// ADC通道定义
#define MQ3_ADC_CHANNEL ADC_Channel_1

// 函数声明
void MQ3_Init(void);
u16 MQ3_Read(void);

#endif

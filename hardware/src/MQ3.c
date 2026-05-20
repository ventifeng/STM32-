#include "mq3.h"
#include "delay.h"

void MQ3_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	
	// 使能GPIO和ADC时钟
	RCC_APB2PeriphClockCmd(MQ3_RCC | RCC_APB2Periph_ADC1, ENABLE);
	
	// 配置GPIO
	GPIO_InitStructure.GPIO_Pin = MQ3_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_Init(MQ3_PORT, &GPIO_InitStructure);
	
	// 配置ADC
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = DISABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel = 1;
	ADC_Init(ADC1, &ADC_InitStructure);
	
	// 使能ADC
	ADC_Cmd(ADC1, ENABLE);
	
	// 校准ADC
	ADC_ResetCalibration(ADC1);
	while(ADC_GetResetCalibrationStatus(ADC1));
	ADC_StartCalibration(ADC1);
	while(ADC_GetCalibrationStatus(ADC1));
}

u16 MQ3_Read(void)
{
	// 配置ADC通道
	ADC_RegularChannelConfig(ADC1, MQ3_ADC_CHANNEL, 1, ADC_SampleTime_239Cycles5);
	
	// 开始转换
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	
	// 等待转换完成
	while(!ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC));
	
	// 返回转换结果
	return ADC_GetConversionValue(ADC1);
}
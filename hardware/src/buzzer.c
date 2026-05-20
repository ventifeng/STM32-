

//��Ƭ��ͷ�ļ�
#include "stm32f10x.h"

//Ӳ������
#include "buzzer.h"


/*
************************************************************
	用于控制高电平触发的有源蜂鸣器
************************************************************
*/
void Buzzer_Init(void)
{

	GPIO_InitTypeDef gpio_initstruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);		//��GPIOA��ʱ��
	
	gpio_initstruct.GPIO_Mode = GPIO_Mode_Out_PP;				//����Ϊ���
	gpio_initstruct.GPIO_Pin = GPIO_Pin_5;						//����ʼ����Pin��
	gpio_initstruct.GPIO_Speed = GPIO_Speed_50MHz;				//�ɳ��ص����Ƶ��
	
	GPIO_Init(GPIOA, &gpio_initstruct);							//��ʼ��GPIO
	
	Buzzer_Set(BUZZER_OFF);													//��ʼ������

}

/*
************************************************************

************************************************************
*/
void Buzzer_Set(_Bool status)
{
	if(status == BUZZER_ON)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);		//���벿��
	}
	else
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);	//���벿��
	}

}

/****************************************************************************
*
*�ļ�����GPIOLed01.c
*
*��  �ܣ�ʹ��PWM1-PWM6������Ϊͨ�õ�I/O��������Basic2812��LED��
*        D1-D6����˸
*
*˵  ������PWM1-PWM6��������ΪI/O�ڣ�����Ϊ�����
*
*��  ��: likyo from hellodsp
*
****************************************************************************/


#include "DSP28_Device.h"
#include "DSP28_Globalprototypes.h"

void delay_loop(void);

#define LED1 GpioDataRegs.GPADAT.bit.GPIOA0
#define LED2 GpioDataRegs.GPADAT.bit.GPIOA1
#define LED3 GpioDataRegs.GPADAT.bit.GPIOA2
#define LED4 GpioDataRegs.GPADAT.bit.GPIOA3
#define LED5 GpioDataRegs.GPADAT.bit.GPIOA4
#define LED6 GpioDataRegs.GPADAT.bit.GPIOA5

/****************************************************************************
*
*��    �ƣ�main()
*
*��    �ܣ�ͨ������PWM1-PWM6��ΪI/O��������Basic2812�ϵ�LED��D1-D6
*          ����������
*
*��ڲ�������
*
*���ڲ�������
*
****************************************************************************/

void main(void)
{
    int kk=0;

    
	InitSysCtrl();  //��ʼ��ϵͳ����

	DINT;
	IER = 0x0000;   //��ֹCPU�ж�
	IFR = 0x0000;   //���CPU�жϱ�־
	
	InitPieCtrl();  //��ʼ��PIE���ƼĴ���

	InitPieVectTable();  //��ʼ��PIE�ж�������	 
	
	InitGpio();  //��ʼ��Gpio��

    while(1)
	{    
	   
	   LED1=1;    //����D1
       LED2=0;    //Ϩ��D2
       LED3=1;    //����D3
       LED4=0;    //Ϩ��D4
       LED5=1;    //����D5
       LED6=0;    //Ϩ��D6

       for(kk=0;kk<100;kk++)	   			  
       delay_loop();  //��ʱ����
    
       LED1=0;    //Ϩ��D1
       LED2=1;    //����D2
       LED3=0;    //Ϩ��D3
       LED4=1;    //����D4
       LED5=0;    //Ϩ��D5
       LED6=1;    //����D6
     
	   for(kk=0;kk<100;kk++)
       delay_loop();  //��ʱ����	
    }
	
} 	


/****************************************************************************
*
*��    �ƣ�delay_loop()
*
*��    �ܣ���ʱ������ʹ��LED�Ƶ�������Ϩ���״̬����һ����ʱ��
*
*��ڲ�������
*
*���ڲ�������
*
****************************************************************************/

void delay_loop()
{
    short      i;
    for (i = 0; i < 30000; i++) {}
}

  
//===========================================================================
// No more.
//===========================================================================


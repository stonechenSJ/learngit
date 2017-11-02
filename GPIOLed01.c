
/****************************************************************************
*
*文件名：GPIOLed01.c
*
*功  能：使用PWM1-PWM6引脚作为通用的I/O口来控制Basic2812上LED灯
*        D1-D6的闪烁
*
*说  明：将PWM1-PWM6引脚配置为I/O口，方向为输出。
*
*作  者: likyo from hellodsp
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
*名    称：main()
*
*功    能：通过引脚PWM1-PWM6作为I/O口来控制Basic2812上的LED等D1-D6
*          的亮或者灭
*
*入口参数：无
*
*出口参数：无
*
****************************************************************************/

void main(void)
{
    int kk=0;

    
	InitSysCtrl();  //初始化系统函数

	DINT;
	IER = 0x0000;   //禁止CPU中断
	IFR = 0x0000;   //清除CPU中断标志
	
	InitPieCtrl();  //初始化PIE控制寄存器

	InitPieVectTable();  //初始化PIE中断向量表	 
	
	InitGpio();  //初始化Gpio口

    while(1)
	{    
	   
	   LED1=1;    //点亮D1
       LED2=0;    //熄灭D2
       LED3=1;    //点亮D3
       LED4=0;    //熄灭D4
       LED5=1;    //点亮D5
       LED6=0;    //熄灭D6

       for(kk=0;kk<100;kk++)	   			  
       delay_loop();  //延时保持
    
       LED1=0;    //熄灭D1
       LED2=1;    //点亮D2
       LED3=0;    //熄灭D3
       LED4=1;    //点亮D4
       LED5=0;    //熄灭D5
       LED6=1;    //点亮D6
     
	   for(kk=0;kk<100;kk++)
       delay_loop();  //延时保持	
    }
	
} 	


/****************************************************************************
*
*名    称：delay_loop()
*
*功    能：延时函数，使得LED灯点亮或者熄灭的状态保持一定的时间
*
*入口参数：无
*
*出口参数：无
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


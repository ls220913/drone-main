
#include "ALL_DEFINE.h"




//           机头      
//   PWM3     ♂       PWM1
//      *           *
//      	*       *
//    		  *   *
//      			*  
//    		  *   *
//      	*       *
//      *           *
//    PWM4           PWM2			
int main(void)
{	
	cycleCounterInit();  //得到系统每个us的系统CLK个数，为以后延时函数，和得到精准的当前执行时间使用
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //2个bit的抢占优先级，2个bit的子优先级
	SysTick_Config(SystemCoreClock / 1000);	//系统滴答时钟

	ALL_Init();//系统初始化
	/*
	 while循环里做一些比较不重要的事情，比如上位机和LED控制。
	其余功能皆安排在中断，整个工程只有一个3ms更新一次的中断，请见scheduler.c里面的工作
	*/
	while(1)
	{
			ANTO_polling(); //匿名上位机发送数据
	//		Usb_Hid_Receive();//USB接收到匿名上位机的数据
			PilotLED(); //LED刷新
	}
}











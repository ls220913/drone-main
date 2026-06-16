

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include "usb_lib.h"
#include "usb_istr.h"
#include "USB_HID.h"
//#include "ano_drv_hid.h"
/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
u8 Transi_Buffer[SendLength];

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : EP1_OUT_Callback.
* Description    : EP1 OUT Callback Routine.
* Input          : None.
* Output         : None.
* Return         : None.
*******************************************************************************/

void EP1_OUT_Callback(void)//stm32接收数完成，中断就会调用这个服务函数
{
		PMAToUserBufferCopy(Hid_RxData, ENDP1_RXADDR,64);//将接收到的数据拷贝出来
		USB_ReceiveFlg = TRUE; //接收完成标志位
		SetEPRxStatus(ENDP1, EP_RX_VALID);
}

void EP2_IN_Callback(void)//stm32发送数据完成，也会调用这个发送完成中断服务函数，这里只是清空缓冲区
{
     u8 ii;
     for (ii=0;ii<SendLength;ii++) Transi_Buffer[ii] = 0x00;
}


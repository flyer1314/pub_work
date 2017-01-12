#ifndef __OBD_UART__
#define __OBD_UART__

#include <stdio.h>

#define OBD_UART_PROCOTOL_HEAD  0xBB    /*帧头*/
#define OBD_UART_PROCOTOL_TAIL  0xEE    /*帧尾*/
#define OBD_UART_PROCOTOL_ESC	0xAA	/*转义*/

#define OBD_UART_PROCOTOL_COMMAND_TIME  0x01    /*【OBD模块】向【主控】申请实时时间*/
#define OBD_UART_PROCOTOL_COMMAND_KEY   0x02    /*【OBD模块】通过【主控】向【服务器】申请身份验证*/
#define OBD_UART_PROCOTOL_COMMAND_SET   0x10    /*【主控】设置【OBD模块】工作参数*/
	/*【主控】读取,存储，清除【OBD模块】识别信息*/
#define OBD_UART_PROCOTOL_COMMAND_MID	0x13	/*读取12字节MCU ID(机器ID)*/
#define OBD_UART_PROCOTOL_COMMAND_VIN	0x14	/*读取车辆底盘号(VIN)*/
#define OBD_UART_PROCOTOL_COMMAND_PTY	0x15	/*读取OBD协议类型及油耗算法*/
#define	OBD_UART_PROCOTOL_COMMAND_NIV	0x16	/*清除【OBD模块】存储的车辆底盘号(VIN)*/
#define OBD_UART_PROCOTOL_COMMAND_INV	0x17	/*发送车辆底盘号(VIN)给【OBD模块】*/

#define OBD_UART_PROCOTOL_COMMAND_SEND	0x20	/*【OBD模块】向【主控】上传事件*/
#define OBD_UART_PROCOTOL_COMMAND_READ	0x30	/*【主控】读取行程内统计参数*/
#define OBD_UART_PROCOTOL_COMMAND_REAE	0x41	/*【主控】读取车辆运行参数*/
#define OBD_UART_PROCOTOL_COMMAND_REAF	0x42	/*【主控】启动【OBD终端】自动上传车辆运行参数*/
#define OBD_UART_PROCOTOL_COMMAND_FAED	0x43	/*【主控】终止【OBD模块】自动上传车辆运行参数*/
#define OBD_UART_PROCOTOL_COMMAND_RERR	0x50	/*【主控】读取车辆故障码*/

#define OBD_UART_PROCOTOL_RED_ERRCODE	0x00	/*读码（车辆故障码）*/
#define OBD_UART_PROCOTOL_CLR_ERRCODE	0x01	/*清码（车辆故障码）*/

#define OBD_PROCOTOL_PID_AA         0x00    /*恢复出厂设置，以下全部参数恢复默认值*/
#define OBD_PROCOTOL_PID_AB         0x01    /*清除终端中存储的行程和事件数据*/
#define OBD_PROCOTOL_PID_AC         0x04    /*故障码扫描时间间隔（单位：S）*/
#define OBD_PROCOTOL_PID_AD         0x05    /*ACC关闭后等多长时间进入睡眠（单位：S）*/
#define OBD_PROCOTOL_PID_AE         0x10    /*重新进行安装位置校准*/
#define OBD_PROCOTOL_PID_AF         0x11    /*开始在线升级*/
#define OBD_PROCOTOL_PID_AG         0x20    /*油耗修正值，单位为1000分之1*/
#define OBD_PROCOTOL_PID_AH         0x21    /*里程修正值，单位为1000分之1*/
#define OBD_PROCOTOL_PID_AI         0x22    /*实际排量m*/
#define OBD_PROCOTOL_PID_AJ         0x30    /*设置震动唤醒阈值0x03~0x7F阈值越大，终端对震动越不敏感*/
#define OBD_PROCOTOL_PID_AK         0x31    /*急加油阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AL         0x32    /*急刹车阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AM         0x33    /*快速变道阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AN         0x34    /*频繁变道阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AO         0x35    /*前碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AP         0x36    /*后碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AQ         0x37    /*左右碰撞阈值调整，公式为:初始阈值X调整值/100*/
#define OBD_PROCOTOL_PID_AR         0x40    /*发动机转速过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_AS         0x41    /*水温过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_AT         0x42    /*水温过低报警阈值，低于阈值报警*/
#define OBD_PROCOTOL_PID_AW         0x43    /*水温恢复提示阈值，高于阈值提示水温恢复*/
#define OBD_PROCOTOL_PID_AX         0x44    /*车速过高报警阈值，高于阈值报警*/
#define OBD_PROCOTOL_PID_AY         0x45    /*电瓶电压过高报警阈值（乘以10后传输）*/
#define OBD_PROCOTOL_PID_AZ         0x46    /*电瓶电压过低报警阈值（乘以10后传输）*/

#define OBD_PROCOTOL_TID_AA			0x01	/*行程开始*/
#define OBD_PROTOCOL_TID_AB			0x02	/*行程结束*/
#define OBD_PROCOTOL_TID_AC			0x03	/*水平校准进行中*/
#define	OBD_PROCOTOL_TID_AD			0x04	/*水平校准完成*/
#define OBD_PROCOTOL_TID_AE			0x05	/*方向校准进行中*/
#define OBD_PROCOTOL_TID_AF			0x06	/*方向校准完成*/	
#define OBD_PROCOTOL_TID_AG         0x07	/*安装位置移动*/
#define OBD_PROCOTOL_TID_AH         0x10	/*急刹车*/
#define OBD_PROCOTOL_TID_AI         0x11	/*急加油*/
#define OBD_PROTOCOL_TID_AJ         0x12	/*快速变道*/
#define OBD_PROCOTOL_TID_AK         0x13	/*弯道加速*/
#define	OBD_PROCOTOL_TID_AL         0x14	/*碰撞*/
#define OBD_PROCOTOL_TID_AM         0x15	/*频繁变道*/
#define OBD_PROCOTOL_TID_AN         0x16	/*乱路高速行驶*/
#define OBD_PROCOTOL_TID_AO         0x17	/*急转弯*/
#define OBD_PROCOTOL_TID_AP         0x18	/*翻车*/
#define OBD_PROCOTOL_TID_AQ         0x19	/*异常震动*/--------------------------------
#define OBD_PROTOCOL_TID_AR         0x20	/*车门异常状态提醒*/
#define OBD_PROCOTOL_TID_AS         0x21	/*胎压和手刹异常状态提醒*/
#define	OBD_PROCOTOL_TID_AT         0x30	/*超速报警*/
#define OBD_PROCOTOL_TID_AU         0x31	/*水温报警*/
#define OBD_PROCOTOL_TID_AV         0x32	/*转速报警*/
#define OBD_PROCOTOL_TID_AW         0x33	/*电平电压报警*/
#define OBD_PROCOTOL_TID_AX         0x34	/*故障报警*/
#define	OBD_PROCOTOL_TID_AY			0x19	/*转弯*/------------------------------------

#endif

/**
 *****************************************************************************************************
  * @copyright	(c)  Shenzhen Saiyuan Microelectronics Co., Ltd
  * @file	SysFunVarDefine.h
  * @author	 
  * @version 	
  * @date	
  * @brief	Store var control and function control extern
  * @details 
 *****************************************************************************************************
 * @attention
 *
 *****************************************************************************************************
 */
#ifndef SYS_FUN_VAR_DEFINE
    #define SYS_FUN_VAR_DEFINE
#include "CustomType.h"
#include "UserExport.h"
#include "FunctionType.h"
#include "CompCtrlDefine.h"
#include "SC_Init.h"
#endif
typedef struct{
	char index[4];
	uint8_t data[32];
}chinesecell_t;
/**************************************Generated by EasyCodeCube*************************************/
//Forbid editing areas between the labels !!!

extern volatile unsigned char TWI0Flag;
extern unsigned char TWI0SendData;
extern unsigned char US0_UART_ReceiveData;
/*************************************.Generated by EasyCodeCube.************************************/
void OLED_menu(void);
void OLED_Showstring(uint8_t x,uint8_t y,char *String);
void OLED_Showchar(uint8_t x,uint8_t y,char Char);
void OLED_showimage(uint8_t x,uint8_t y,uint8_t width,uint8_t height, uint8_t *image);
void OLED_Showchinese(uint8_t x,uint8_t y,char *chinese);
void Menu_Interface(void);
void OLED_showlight(uint8_t m);
void OLED_shownumber(uint8_t x,uint8_t y,uint8_t k);
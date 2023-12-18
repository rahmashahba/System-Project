/*
 * calc.h


 *
 *  Created on: Nov 23, 2023
 *      Author: rahma
 */
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>
uint8 Local_u8Hamoksha[9] = {
		0b00001110,
		0b00001110,
		0b00000100,
		0b00001110,
		0b00010101,
		0b00000100,
		0b00001110,
		0b00010001,0};
uint8 Local_u8HamokshaRUN[9] = {
		0b00001110,
		0b00001110,
		0b00000100,
		0b00001111,
		0b00010100,
		0b00000100,
		0b00001010,
		0b00000001,0};



void Hamoksha(void)
{

	//CLCD_u8SendString("Welcome to Motor DashBoard ");
	//_delay_ms(20000);
	for(uint8 i=0;i<16;i++)
	{
		CLCD_voidGoToXY(4,0);
		CLCD_u8SendString("Welcome  ");
		CLCD_u8SendSpecialCharacter(0,Local_u8Hamoksha,i,1);
		CLCD_u8SendSpecialCharacter(0,Local_u8HamokshaRUN,i,1);
		_delay_ms(100);
		CLCD_voidSendCmd(1);

	}

}
void HamokshaBack(void)
{


	for(uint8 i=16;i>=8;i--)
	{
		CLCD_voidGoToXY(4,0);
		CLCD_u8SendString("Good bye ");
		CLCD_u8SendSpecialCharacter(0,Local_u8Hamoksha,i,1);
		CLCD_u8SendSpecialCharacter(0,Local_u8HamokshaRUN,i,1);
		_delay_ms(100);
		CLCD_voidSendCmd(1);


	}
	//CLCD_voidSendCmd(1);

}


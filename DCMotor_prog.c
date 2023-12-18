/*
 * DCMotor_prog.c
 *
 *  Created on: Nov 27, 2023
 *      Author: omnia sherief
 */

#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "DCMotor_interface.h"
#include "DCMotor_cfg.h"
#include <util/delay.h>
void DcMotor_CW()
{
	//CLCD_voidSendCmd(1);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
	_delay_ms(20);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_HIGH);

}
void DcMotor_CCW()
{
	//CLCD_voidSendCmd(1);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
	_delay_ms(20);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_HIGH);
}
void DcMotor_Stop()
{
	//CLCD_voidSendCmd(1);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN6,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN7,DIO_u8PIN_LOW);
}

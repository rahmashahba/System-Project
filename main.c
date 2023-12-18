/*
 * main.c
 *
 *  Created on: Nov 18, 2023
 *      Author: rahma
 */

#include "STD_TYPES.h"
#include <util/delay.h>
#include "ErrType.h"

#include  "PORT_interface.h"
#include  "DIO_interface.h"
#include  "CLCD_interface.h"
#include  "KPD_interface.h"
#include  "EXTI_interface.h"
#include  "GIE_interface.h"
#include  "Hamoksha.h"
#include  "DCMotor_interface.h"


void SetSysFlag(void);
uint8 Global_u8SystemFlag = 0 ;


void main(void)
{
	uint8 Localu8KeyPadKey ;
	uint16 Local_u8Angle = 0;
	uint8 Local_u8Flag = 1;
	uint8 test=0;
	DcMotor_Stop();


	/************************Drivers Initialization ********************************************************/
	PORT_voidInit();
	CLCD_voidInit();
	EXTI_voidInit();


	/************************global interrupt enable ********************************************************/
	GIE_voidEnableGlobal();


	/************************Send ISR functions address *****************************************************/
	EXTI_u8SetCallBack(INT2,&SetSysFlag);





	while(1)
	{
		/*/*enable the INT2 */
		EXTI_u8EnableIntChannel(INT2);

		/*enter the system when ISR function sets the Global Flag */
		while(Global_u8SystemFlag==1)
		{
			/*disable the INT2 */
			EXTI_u8DisableIntChannel(INT2);
			Hamoksha();
			CLCD_u8SendString("Enter password:");
			CLCD_voidGoToXY(1,1);


			do
			{
				_delay_ms(100);
				do
				{
					Localu8KeyPadKey= KPD_u8GetPressedKey();
				}
				while(Localu8KeyPadKey == 0xff);
				//CLCD_voidSendNumber(Localu8KeyPadKey);
				if(Localu8KeyPadKey =='=')
				{
					CLCD_voidGoToXY(1,1);
					CLCD_u8SendString("***");
					_delay_ms(1000);
					if (Local_u8Angle ==123)
					{

						DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
						_delay_ms(1000);
						CLCD_voidSendCmd(1);
						CLCD_voidGoToXY(3,0);
						CLCD_u8SendString("Correct");
						DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_HIGH);
						_delay_ms(3000);
						Local_u8Angle=0;
						Local_u8Flag =0;
						test=0;

					}
					else
					{

						DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
						CLCD_voidSendCmd(1);
						CLCD_u8SendString("Try Again!");
						_delay_ms(1100);
						CLCD_voidSendCmd(1);
						test++;
						CLCD_u8SendString("Enter password:");
						CLCD_voidGoToXY(1,1);
						DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
						Global_u8SystemFlag = 0 ;
						Local_u8Angle=0;


					}
				}
				else if((Localu8KeyPadKey >=0) && (Localu8KeyPadKey <=9))
				{
					CLCD_voidSendNumber(Localu8KeyPadKey);
					Local_u8Angle = Local_u8Angle*(uint16)10 + (uint16)Localu8KeyPadKey;
				}
				if(test==3)
				{
					Global_u8SystemFlag = 0;
					Local_u8Flag =0;
					DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
					CLCD_voidSendCmd(1);
					CLCD_u8SendString("Invalid password");
					_delay_ms(2200);
					test=0;
					CLCD_voidSendCmd(1);
				}
			}
			while(Local_u8Flag==1);


			/*if Global flag =0  close the system */
			if( Global_u8SystemFlag == 0 )
			{
				CLCD_voidSendCmd(1);
				CLCD_voidGoToXY(5,0);
				CLCD_u8SendString("Close");
				_delay_ms(1111);
				HamokshaBack();
				CLCD_voidSendCmd(1);
				Local_u8Angle=0;
				DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
				Local_u8Flag=1;
				break;
			}

			/********** in case of right password ******************/

			/*Enable INT2 interrupt */
			Global_u8SystemFlag = 0;
			EXTI_u8EnableIntChannel(INT2);
			CLCD_voidSendCmd(1);
			CLCD_voidGoToXY(3,0);
			CLCD_u8SendString("System On");

			/*Motor rotates */
			if(Global_u8SystemFlag == 0)
			{
				DcMotor_CW();
				_delay_ms(5000);
				DcMotor_Stop();
				DcMotor_CCW();
				_delay_ms(5000);
				Local_u8Angle=0;

				//DcMotor_Stop();
			}

			/*Close the system  */
			DcMotor_Stop();
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN0,DIO_u8PIN_LOW);
			Global_u8SystemFlag = 0;
			CLCD_voidSendCmd(1);
			CLCD_voidGoToXY(5,0);
			HamokshaBack();
			CLCD_voidSendCmd(1);
			Local_u8Flag=1;
			break;



		}
	}
}


void SetSysFlag(void)
{
	Global_u8SystemFlag = 1 ;
}

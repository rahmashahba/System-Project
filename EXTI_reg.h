#ifndef EXTI_REG_H
#define EXTI_REG_H

#define GICR 	        *((volatile uint8*)0x5B)  //General interrupt control register

#define GICR_INT1       7u						 //Int1 Bit
#define GICR_INT0       6u                       //Int0 Bit
#define GICR_INT2       5u                       //Int2 Bit

#define MCUCR 	        *((volatile uint8*)0x55) //MCU control register

#define MCUCR_ISC00     0u                     // Int0 Sense CONTRAL bit 0
#define MCUCR_ISC01     1u                     // Int0 Sense CONTRAL bit 1
#define MCUCR_ISC10     2u                     // Int1 Sense CONTRAL bit 0
#define MCUCR_ISC11     3u                     // Int1 Sense CONTRAL bit 1


#define MCUCSR          *((volatile uint8*)0x54) //MCU control and status

#define MCUCSR_ISC2     6u                      //Int2 Sense Contral bit

#endif

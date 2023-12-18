#ifndef EXTI_CFG_H
#define EXTI_CFG_H

/* CONFIGURE the sense ctrl option for INT0 Channel , options:
1-LOW_LEVEL
2-ON_CHANGE
3-FALLING_EDGE
4-RISING_EDGE
	*/
#define INT0_SENSE_CTRL   EXTI_FALLING_EDGE


/* CONFIGURE the sense ctrl option for INT0 Channel , options:

1-EXTI_LOW_LEVEL
2-EXTI_ON_CHANGE
3-EXIT_FALLING_EDGE
4-EXIT_RISING_EDGE
	*/
#define INT1_SENSE_CTRL   EXTI_FALLING_EDGE


/* CONFIGURE the sense ctrl option for INT0 Channel , options:

1-FALLING_EDGE
2-RISING_EDGE
	*/
#define INT2_SENSE_CTRL    EXTI_FALLING_EDGE


/* CONFIGURE the sense ctrl option for INT0 Channel , options:

1-ENABLED
2-DISABLED
	*/
#define INT0_INIT_STATE    ENABLED


/* CONFIGURE the sense ctrl option for INT0 Channel , options:

1-ENABLE
2-DISABLED
	*/
#define INT1_INIT_STATE    ENABLED


/* CONFIGURE the sense ctrl option for INT0 Channel , options:

1-ENABLED
2-DISANABLED
	*/

#define INT2_INIT_STATE    DISABLED

#endif

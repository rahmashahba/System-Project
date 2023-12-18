#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "ErrType.h"


#include "GIE_reg.h"
#include "GIE_interface.h"
void GIE_voidEnableGlobal(void )
{
	//SET_BIT(SREG ,SREG_I);
	__asm volatile("SEI"); //INLINE ASSEMBLY :Set i Bit better than SET_BIT(SREG ,SREG_I) take one clock cycle
}

void GIE_voidDisanableGlobal(void )
{
	__asm volatile("CLI"); //INLINE ASSEMBLY :Clear i Bit
//	CLR_BIT(SREG ,SREG_I);
}

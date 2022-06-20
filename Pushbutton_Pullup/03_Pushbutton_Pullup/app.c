//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "app.h"
#include "clock.h"

void AppInit(void)
{
	ClocksInit();
	
	// Assign LED0 as OUTPUT
	REG_PORT_DIR0 = LED0_PIN_MASK;
	
	// Set LED0 OFF
	REG_PORT_OUTCLR0 = LED0_PIN_MASK;
	
	// Assign Switch on PA16 as INPUT
	//PORT->Group[0].PINCFG[16].reg = PORT_PINCFG_INEN;
	PORT->Group[0].PINCFG[16].bit.INEN = 1; 

} // AppInit()

void AppRun(void)
{
	// Set the drive strength to strong
	PORT->Group[LED0_PORT].PINCFG[LED0_PIN_NUMBER].bit.DRVSTR = 1;
	
	while(1)
	{
		
		// pull up 
		// so we keep LED off
		uint32_t aa = PORT->Group[0].IN.reg;
		if((aa & 0x00010000)== 0x00010000)
		{
			// keep LED off
			
			REG_PORT_OUTSET0 = LED0_PIN_MASK;
			
		}
		
		else
		{
			// turn LED on
			REG_PORT_OUTCLR0 = LED0_PIN_MASK;
			
		}
	}

} // Apprun()


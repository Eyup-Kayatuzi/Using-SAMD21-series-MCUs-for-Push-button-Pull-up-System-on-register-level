//////////////////////////////////////////////////////////////////////////
// Include and defines
//////////////////////////////////////////////////////////////////////////
#include "sam.h"
#include "definitions.h"
#include "app.h"

//////////////////////////////////////////////////////////////////////////
// Function Prototypes
//////////////////////////////////////////////////////////////////////////
void ClocksInit(void);	// Configure Clock, Wait States and synch, bus clocks for 48MHz operation

int main(void)
{
	// CMSIS compliant function not used
	//SystemInit();
	
	// Application hardware and software initialization 
	AppInit();

	// Super loop
	while(1)
	{
		// Run your application
		AppRun();
	}
} // main()





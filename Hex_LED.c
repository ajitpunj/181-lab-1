// Simple test program


int main(void)
{
	volatile int* led	= (int*) 0xFF200040; // red LED address
	volatile int* switchptr	= (int*) 0xFF200030; // SW slider switch address
	
	volatile int* hex3_hex0 = (int*) 0xFF200020;
	volatile int* hex5_hex4 = (int*) 0xFF200010;
	volatile int* pushbuttons = (int*) 0xFF200000;

	int * hex3_hex0_test = (int*) 0xFF200020;

	int switch_value;
	int pushbuttons_value;

	bool phrase = true; 
		
	int array_state_1[ = {0, 118,
	int arrat_state_2[ = {  

	while( 1 )
	{ 
		pushbuttons_value = *(pushbuttons);

		if (pushbuttons_value == 8){
			continue;
		}

		if (pushbuttons_value == 1){
			phrase = !phrase;
		}

		while (phrase == true)
		{
			pushbuttons_value = *(pushbuttons);
			if (pushbuttons_value == 8){
				continue;
			}
			if (pushbuttons_value == 1){
				phrase = ~phrase;
				break;
			}
			switch_value = *(switchptr);
			*(led) = switch_value;

			if (pushbuttons_value == 1 ){
			
				*(hex3_hex0) = 118;		//H = 118
				*(hex3_hex0) = 16246;
 			}
			if (pushbuttons_value == 8){
				*(hex3_hex0) = 0;
			}
		}

		if (phrase == false) 
		{
			//switch mode
		}
 
	}
	
}

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
            //set addresses to values ie base address of hex displays to
            // value of H, then next loop iteration set base address to next letter
            //and next address of hex displays to base hex address
                      
            //initialize all displays to off
            int letterState=0;
			if (pushbuttons_value == 1 ){ //speed control?
                //set each display = to value of one before it (hex1=hex0)
                      int* hexDispAddr = (int*) 0xFF200020; //TODO add one address spot to get to next hex display
                      for(int i=0;i<6;i++){ //repeat 6 times to switch each hex display 
                            *(hexDispAddr)=*(hexDispAddr-4); //hexDispAddr = to value of display before this one
                            hexDispAddr=hexDispAddr+4;
                      }
               
                //*(hex3_hex0)=118;
                //switch case or if-else statements to determine hex0 value
                    if (letterState==0)
                      *(hex3_hex0)=118;
                    else if (letterState==1)
                      //*(hex3_hex0)=118;= E
                    
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

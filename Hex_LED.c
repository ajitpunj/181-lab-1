//Part 3 full code


int main(void)
{
	volatile int* led	= (int*) 0xFF200040; // red LED address
	volatile int* switchptr	= (int*) 0xFF200030; // SW slider switch address
	
	volatile int* hex3_hex0 = (int*) 0xFF200020;
	volatile int* hex5_hex4 = (int*) 0xFF200010;
	volatile int* pushbuttons = (int*) 0xFF200000;

	int * hex3_hex0_test = (int*) 0xFF200020;

	int switch_value;
	int pushbuttons_value, pushbuttons_value2;
	int i,n,true,pause,c,l,p, temp, checkPaused, hold, bob;
	int speed;
	int increment; 
	int first_part, second_part;
 
	int array_state_1[13] = {943210240, 943652926, 1056980542, 4079167, 1044266832, 1044336696, 1062221918, 1345871360, 945684598, 1577088633, 7764280, 1987655736, 2033727551};
	int array_state_2[13] = {30329, 31032, 14392, 14399, 16128, 62, 15934, 15935, 16208, 20536, 14430, 24064, 118}; 

	int array_state_3[4] = {256,512,768,1024};
	speed = 5;
	true = 0;
	pause = 0;
	hold = 0;
	l = 0;
	i = 0;
	checkPaused = 0;
	while(1){
				
			// Hello World Loop 
			
			i = i % 13;
			l = l % 4;
			pushbuttons_value = *(pushbuttons);
			
			if (pushbuttons_value == 8){
				true = !true; 
				for (p=0; p <(20*(10000));p++){
			
					switch_value = *(switchptr);
					*(led) = switch_value;
				}
			}
			if (pushbuttons_value == 1){
				/*hold = !hold;
				if (hold==1)
					continue;*/
				checkPaused=1;
				/*while(checkPaused){
					pushbuttons_value=*(pushbuttons);
					if(pushbuttons_value==1){
						checkPaused=0;
					}
				}
				temp = speed;*/ 
				//speed = 10000;
				for (c=0; c <(30*(10000));c++){
			
					switch_value = *(switchptr);
					*(led) = switch_value;
				}/*
				for (c=0; c <(20*(10000));c++){
			
					switch_value = *(switchptr);
					*(led) = switch_value;
				}
				continue;*/
			}
			while(checkPaused==1){
				int backtozero;
				pushbuttons_value2 = *(pushbuttons);
				//initially, wait for pushbuttons to go back to 0 state
				if(pushbuttons_value2==0)
					backtozero=1;
				//after button is unpressed, check for value to be 1 again
				if(pushbuttons_value2==1 && backtozero==1){
					checkPaused=0;
					for (c=0; c <(70*(10000));c++){
			
					switch_value = *(switchptr);
					*(led) = switch_value;
					}
				}
			}
			
				
			switch_value = *(switchptr);
			*(led) = switch_value;
			
			if (true==0){
				*(hex3_hex0) = array_state_1[i];		
				*(hex5_hex4) = array_state_2[i];
				i = i + 1;
			}
			else{
				first_part = switch_value/(128);
				first_part = first_part*256;
				second_part = switch_value%256;
				bob = multi(l);
				*(hex3_hex0) = (first_part+second_part)*(bob);
				*(hex5_hex4) = 0;
				l = l + 1;
			}
			
			if (pushbuttons_value==4){
				speed = speed - 1;
			}
				
			if (pushbuttons_value==2){
				speed = speed + 1;
			}
			
			
			for (n=0; n <(speed*(10000));n++){
				pushbuttons_value = *(pushbuttons);
				/*if (pushbuttons_value==1){
					
					speed = temp;
					break;
					
				} */
				switch_value = *(switchptr);
				*(led) = switch_value;
			}
			/*while(1){
				pushbuttons_value = *(pushbuttons);
				if(checkPaused==1){
					if (pushbuttons_value == 1){
						checkPaused = 0;
					}
				}
			
				if (checkPaused == 0){				
					while(1){
						pushbuttons_value = *(pushbuttons);
						if (pushbuttons_value==0)
							break;
					}
					break;
				}
				
			}*/
			
			
		
	}
}

int multi(int l){
	int c;
	int output;
	output = 1;
	for (c=0; c<l;c++){
		output = output*256;
	}
	return (output);
}




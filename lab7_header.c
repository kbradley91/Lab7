#include <DSP28x_Project.h>
#include "DSP_KB.h"
#include "lab7_header.h"
#include "string.h"



void init_buffer(){
	int i;
	for(i = 0;i<FILTER_TAP_NUM;i++)
		inputArray[i] = 0;

}
interrupt void lowpass_ISR(void){
	unsigned int input = ADC_get();

	//here we will convolve the input with the FIR filter that acts as a low pass filter

	// incrementing the circular buffer, we can modulate it each time to ensure it goes back to the
	// correct location even if it goes above its bounds

	*start = input;
	start++;
	cBuffer = start;


	int i;

	float y = 0;
	unsigned int * temp;
	unsigned int temp2;
	for(i = 0; i<FILTER_TAP_NUM;i++){
		//unsigned int temp2 = (i%FILTER_TAP_NUM);
		cBuffer--;
		if(cBuffer<arrayStart){
					cBuffer = arrayEnd;
					//cBuffer = arrayStart;
		}
		temp2 = *cBuffer;
		y += filter_taps[i] * temp2;
	}

	if((start > arrayEnd)){
		start = arrayStart;
	}


	DAC_set(y);


}

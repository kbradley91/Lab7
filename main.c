
#include <DSP28x_Project.h>
#include "DSP_KB.h"
#include "lab7_header.h"


unsigned long ISRvalue = &lowpass_ISR;

/*

FIR filter designed with
http://t-filter.appspot.com

sampling frequency: 48000 Hz

* 0 Hz - 900 Hz
  gain = 1
  desired ripple = 3 dB
  actual ripple = 2.1883096767320174 dB

* 3000 Hz - 15000 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -40.67839495037705 dB

*/





int main(void) {
	
	DisableDog();
	CPUinit();
	EALLOW;
	outputEnable();
	LCDinit();
	LCDclear();
	initADC();
	DAC_init();
	init_buffer();
	timerINIT(ISRvalue, samplingRate);

	while(1){

	}


	return 0;
}

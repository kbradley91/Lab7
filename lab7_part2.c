
#include <DSP28x_Project.h>
#include "DSP_KB.h"
#include "FPU.h"
//#include "lab7_header.h"

FIR_FP firFP = FIR_FP_DEFAULTS;

interrupt void lowpass_isr2(void);
unsigned long ISRvalue = &lowpass_isr2;
#define FILTER_TAP_NUM2 19
#define FIR_ORDER2 FILTER_TAP_NUM2-1

#define FILTER_TAP_NUM 32
float dbuffer[FILTER_TAP_NUM2];

#define FIR_ORDER FILTER_TAP_NUM2-1
/*

FIR filter designed with
http://t-filter.appspot.com

sampling frequency: 30000 Hz

* 0 Hz - 100 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = 15.286848637846257 dB

* 400 Hz - 800 Hz
  gain = 1
  desired ripple = 5 dB
  actual ripple = 2.558483328963861 dB

* 1200 Hz - 10000 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = 48.871167777118664 dB

*/



const double filter_taps[FILTER_TAP_NUM] = {
		-0.201971327143998960,
		0.006343361237706141,
		0.007349423690535509,
		0.009112535037192449,
		0.011537629267679589,
		0.014452654365759302,
		0.017818115558127789,
		0.021415477211861961,
		0.025195858984107505,
		0.028921573832129559,
		0.032545069147767565,
		0.035833015548334048,
		0.038757340367418333,
		0.041110229873360223,
		0.042900373714393904,
		0.043962233842115922,
		0.044353855721929417,
		0.043962233842115922,
		0.042900373714393904,
		0.041110229873360223,
		0.038757340367418333,
		0.035833015548334048,
		0.032545069147767565,
		0.028921573832129559,
		0.025195858984107505,
		0.021415477211861961,
		0.017818115558127789,
		0.014452654365759302,
		0.011537629267679589,
		0.009112535037192449,
		0.007349423690535509,
		0.006343361237706141,
		-0.201971327143998960
};

/*

FIR filter designed with
http://t-filter.appspot.com

sampling frequency: 30000 Hz

* 0 Hz - 2000 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -42.131464250808946 dB

* 4000 Hz - 12000 Hz
  gain = 1
  desired ripple = 3 dB
  actual ripple = 1.8484227119898664 dB

*/



const double filter_taps2[FILTER_TAP_NUM2] = {
  -0.10695780749088056,
  0.23886656960484884,
  -0.32734953207600204,
  0.5936653235830194,
  -0.7624007961327635,
  0.9772563985565024,
  -1.3091217558036101,
  1.2422495368818611,
  -1.7081530170362385,
  2.331714122817168,
  -1.7081530170362385,
  1.242249536881861,
  -1.3091217558036101,
  0.9772563985565024,
  -0.7624007961327635,
  0.5936653235830193,
  -0.32734953207600204,
  0.23886656960484878,
  -0.10695780749088056
};







int main(){
	DisableDog();
	CPUinit();
	EALLOW;
	outputEnable();
	LCDinit();
	LCDclear();
	initADC();
	DAC_init();
	//init_buffer();


	//INITIALIZING TI FIR STUFF

	firFP.order = FIR_ORDER;
	firFP.dbuffer_ptr = dbuffer;
	firFP.coeff_ptr = (float *)filter_taps;
	firFP.init(&firFP);






	timerINIT(ISRvalue, samplingRate);
	EALLOW;
	while(1){

	}






	return 0;
}

interrupt void lowpass_isr2(void){

	firFP.input = ADC_get();

	firFP.calc(&firFP);

	DAC_set(firFP.output);




}

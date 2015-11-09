/*
 * lab7_header.h
 *
 *  Created on: Nov 8, 2015
 *      Author: Kyle
 */

#ifndef LAB7_HEADER_H_
#define LAB7_HEADER_H_


/*

FIR filter designed with
http://t-filter.appspot.com

sampling frequency: 30000 Hz

* 0 Hz - 900 Hz
  gain = 1
  desired ripple = 3 dB
  actual ripple = 1.7853897782538837 dB

* 3000 Hz - 15000 Hz
  gain = 0
  desired attenuation = -40 dB
  actual attenuation = -42.43064293514517 dB

*/

#define FILTER_TAP_NUM 25

static double filter_taps[FILTER_TAP_NUM] = {
  -0.005327879388107727,
  -0.0028344703381101136,
  -0.0011640557444328322,
  0.0032194436044128746,
  0.01098646698666558,
  0.02237672409016667,
  0.03706889277000161,
  0.054118185805110006,
  0.072006619935645,
  0.08884816993075813,
  0.10267695389389962,
  0.11176545116155456,
  0.11493395054432909,
  0.11176545116155456,
  0.10267695389389962,
  0.08884816993075813,
  0.072006619935645,
  0.054118185805110006,
  0.03706889277000161,
  0.022376724090166666,
  0.01098646698666558,
  0.0032194436044128746,
  -0.0011640557444328322,
  -0.0028344703381101128,
  -0.005327879388107727
};

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



static double filter_taps2[FILTER_TAP_NUM] = {
  0.24317447703956133,
  -1.1292199282982551,
  3.6008478930273804,
  -8.499195505950656,
  16.768791834069543,
  -28.145604199736418,
  41.87224899795781,
  -55.6901247727043,
  67.92139638012753,
  -76.68882250559673,
  82.19347007186227,
  -84.61377375990357,
  85.4589291658306,
  -84.61377375990357,
  82.19347007186227,
  -76.68882250559673,
  67.92139638012753,
  -55.6901247727043,
  41.87224899795781,
  -28.145604199736418,
  16.768791834069543,
  -8.499195505950656,
  3.6008478930273804,
  -1.1292199282982551,
  0.24317447703956133
};



static unsigned int inputArray[25]; //intialzating a section of memory to hold my buffer
static unsigned int * start = &inputArray[0];
static unsigned int * cBuffer = &inputArray[0];
static unsigned int * arrayStart = &inputArray[0];
static unsigned int * arrayEnd = &inputArray[24];
//static double * cBuffer = &inputArray[0]; // circular buffer
//static double * holdingPointer = &inputArray[0];


interrupt void lowpass_ISR(void);
void init_buffer();



#endif /* LAB7_HEADER_H_ */

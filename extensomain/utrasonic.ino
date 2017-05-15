bool data_filled = 0;

static uint16_t signal[N_BUFFER];
uint8_t edge = 0;

void myHandler(){
  REG_PIOB_ODSR ^= (1<<25);
  edge += 1;
  if (edge>1){
    edge = 0;
    Timer3.stop();
  }
}

void waitForTime(){  
	Timer3.attachInterrupt(myHandler);
	delay(1000);      
	Timer3.start(100); // Calls every 50ms
}

void sampleSignal(uint16_t ch){
  initADC(signal);

  adc_start(ADC);
  delay(5);  
  adc_stop(ADC);
}

void getUltrasonicWave(){
	Serial.println("ultrasonic");
}
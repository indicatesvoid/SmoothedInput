// As per http://arduino.cc/en/Tutorial/Smoothing

#pragma once

#include "Arduino.h"

class SmoothedInput {
  public:
  
    SmoothedInput(int _pin, int _smoothness) {
      inputPin = _pin;
      numReadings = _smoothness;
      
      index = total = average = 0;
    }

    SmoothedInput(int _pin) {
      inputPin = _pin;
      numReadings = 10;

      index = total = average = 0;
    }
    
    void init() {
      // init all readings to 0
      for(int reading = 0; reading < numReadings; reading++) readings[reading] = 0;
    }
    
    void smooth() {    
      total = total - readings[index];
      readings[index] = analogRead(inputPin);
      total = total + readings[index];
      index = index + 1;
      
      if(index >= numReadings) index = 0;
      
      average = total / numReadings;
      
      // delay between reads for stability
      delay(1);
    }
    
    int getCurrentReading() {
      return readings[index];
    }
    
    int getSmoothedReading() {
        return average;
    }
    
  private:
    int inputPin;
    int numReadings;
    int readings[numReadings];
    int index;
    int total;
    int average;
};
  
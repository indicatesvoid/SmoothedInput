SmoothedInput.h
=========

A class encapsulation of input smoothing for analog inputs on the Arduino, as per http://arduino.cc/en/Tutorial/Smoothing

Usage
----
1) Place the file inside your sketch folder.

2) Include the file:

```
#include SmoothedInput.h
```

3) Instantiate as many SmoothedInput objects as you like, using the constructor SmoothedInput(_pin, _smoothness), where _pin is the input pin, and _smoothness is the size of the sample set (more samples = more 'smoothness', but slower response time):

```
SmoothedInput firstInput = SmoothedInput(0, 20);
SmoothedInput secondInput = SmoothedInput(1, 20);
```

If you omit the _smoothness property, a default of 10 samples will be used:

```
// use default of 10 samples
SmoothedInput thirdInput = SmoothedInput(2);
```

4) Call the 'init' function on each SmoothedInput object (probably in your setup() function). init() only needs to be called once on every object:
```
void setup() {
    firstInput.init();
    secondInput.init();
    thirdInput.init();
}
```

5) In your loop() function, call the 'smooth' function on each SmoothedInput object:
```
void loop() {
    firstInput.smooth();
    secondInput.smooth();
    thirdInput.smooth();
}
```

6) Use the 'getSmoothedReading' function to retrieve the smoothed value, or the 'getCurrentReading' function to get the raw, unsmoothed value from your sensor:

```
Serial.println(firstInput.getSmoothedReading()); // prints smoothed reading
Serial.println(firstInput.getCurrentReading()); // prints raw (unsmoothed) reading
```
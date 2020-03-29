/*
  
 Author: Allen Downey 
 
 Based on http://arduino.cc/en/Tutorial/AnalogInput
 Created by David Cuartielles
 modified 30 Aug 2011
 By Tom Igoe
 License: Public Domain
 
 */
 
 
int ledPin = 5;       // select the pin for the LED
int buttonPin1 = 2;
int buttonPin2 = 3;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  

  pinMode(ledPin, OUTPUT);
  
  pinMode(13, OUTPUT);  
  pinMode(12, OUTPUT);  
  pinMode(11, OUTPUT);  
  pinMode(10, OUTPUT);  
  pinMode(9, OUTPUT);  
  pinMode(8, OUTPUT);  
  pinMode(7, OUTPUT);  
  pinMode(6, OUTPUT);  
}

void writeByte(int x) {
  int pin;
  
  for (pin=13; pin>=6; pin--) {
    digitalWrite(pin, x&1);
    x >>= 1;
  }
}

int low = 36;
int high = 255;
int stride = 5;
int counter = low;
int sine_arr[] = {127, 134, 142, 150, 158, 166, 173, 181, 188, 195, 201, 207, 213, 219, 224, 229, 234, 238, 241, 245, 247, 250, 251, 252, 253, 254, 253, 252, 251, 250, 247, 245, 241, 238, 234, 229, 224, 219, 213, 207, 201, 195, 188, 181, 173, 166, 158, 150, 142, 134, 127, 119, 111, 103, 95, 87, 80, 72, 65, 58, 52, 46, 40, 34, 29, 24, 19, 15, 12, 8, 6, 3, 2, 1, 0, 0, 0, 1, 2, 3, 6, 8, 12, 15, 19, 24, 29, 34, 40, 46, 52, 58, 65, 72, 80, 87, 95, 103, 111, 119,};
double rads = 0;
size_t len = sizeof(sine_arr)/sizeof(sine_arr[0]);

int sine(int freq) {
  rads = millis()/1000.0*freq;
  Serial.println(millis());
  Serial.println(rads);
  Serial.println(int(rads));
  return sine_arr[int(rads)%len];
}


void loop() {
  int buttonSaw = digitalRead(buttonPin1);
  int buttonSine = digitalRead(buttonPin2);
  // if (buttonSine && buttonSaw) return;

  if (!buttonSaw) { 
    counter += stride;
    if (counter > high) {
      counter = low;
      //Serial.println(counter);
    } 
    writeByte(counter);
  }


  if (!buttonSine) {
    // Serial.println(s);
    writeByte(sine(150));
  }

  // write to the digital pins  
}

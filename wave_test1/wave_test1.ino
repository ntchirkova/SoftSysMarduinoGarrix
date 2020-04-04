/*
 Author: Nina Tchirkova and Samantha Young
 Based on Allen Downey's Code and http://arduino.cc/en/Tutorial/AnalogInput 
 */
 
 
int buttonPin1 = 2;
int buttonPin2 = 3;
int buttonPin3 = 4;

void setup() {
  Serial.begin(9600);
  
  pinMode(buttonPin1, INPUT_PULLUP);  
  pinMode(buttonPin2, INPUT_PULLUP);  
  pinMode(buttonPin3, INPUT_PULLUP); 
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

int square_count = 0;
int square_value = 250;
int saw_value = 0;
int increase = 1;
int sine_arr[] = {127, 134, 142, 150, 158, 166, 173, 181, 188, 195, 201, 207, 213, 219, 224, 229, 234, 238, 241, 245, 247, 250, 251, 252, 253, 254, 253, 252, 251, 250, 247, 245, 241, 238, 234, 229, 224, 219, 213, 207, 201, 195, 188, 181, 173, 166, 158, 150, 142, 134, 127, 119, 111, 103, 95, 87, 80, 72, 65, 58, 52, 46, 40, 34, 29, 24, 19, 15, 12, 8, 6, 3, 2, 1, 0, 0, 0, 1, 2, 3, 6, 8, 12, 15, 19, 24, 29, 34, 40, 46, 52, 58, 65, 72, 80, 87, 95, 103, 111, 119,};
int rads = 0;
int t = 0;
int frequency = 0;

int getFreqFromSlider(){
  int in = 0;
  int freq = 0;
  in = analogRead(A0);
  freq = map(in, 0, 1024, 0, 11);
  return freq;
}

size_t len = sizeof(sine_arr)/sizeof(sine_arr[0]);

// Low freq is 1 and high freq is 10
int square(int freq){
  if (square_count > ((10-freq)+1)*5) {
    square_count = 0;
    if (square_value > 0) {
      square_value = 0;
    } else {
      square_value = 250;
    }
  }
  square_count++;
  return square_value;
}

// Low freq is 1 and high freq is 10
int sine(int freq) {
  rads = rads + freq;
  if (rads > len) {
    rads = rads%len;
  }
  return sine_arr[rads];
}

// Low freq is 1 and high freq is 10
int saw(int freq) { 
  int m = map(freq, 1, 10, 3, 23);
  if (saw_value > 250) {
    increase = -1;
  } else if (saw_value < 1) {
    increase = 1;
  }
  saw_value = saw_value + increase*m;
  return saw_value;
}

void loop() {
  int buttonSquare = digitalRead(buttonPin1);
  int buttonSine = digitalRead(buttonPin2);
  int buttonSaw = digitalRead(buttonPin3);

  frequency = getFreqFromSlider();
  if (buttonSine && buttonSaw && buttonSquare ) return;
  if (!buttonSquare) { 
    writeByte(square(frequency));
  }
  if (!buttonSine) {
    writeByte(sine(frequency));
  }
  if (!buttonSaw) {
    writeByte(saw(frequency));
  }

}

// 4 step sequencer for arduino and Max msp by Katie Laffan.
//  LEDS connected on pins 2, 3 4, 7. Analog sensor A0. Button pin - 11. Download ezButton library for button. 
int LED1 = 7;
int LED2 = 4;
int LED3 = 3;
int LED4 = 2;//Initialise LEDS

const int sensorPin = A0; //intitialise Potentiometer
int sensorVal= 0; //sensor value is at 0

#include <ezButton.h> // include the library - debounce buttons easily
ezButton button(11); // initailise button

void setup() {

pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);
pinMode(LED3, OUTPUT);
pinMode(LED4, OUTPUT);// set LEDS as outputs
button.setDebounceTime(50); // debounce time 50 - higher number if still flickering
Serial.begin(9600); // baudrate
}

void loop() {
  
  digitalWrite(LED4, LOW);    // turn off LED4
  digitalWrite(LED1, HIGH);    // turn on LED1
  sensorVal = analogRead(sensorPin);
  delay(sensorVal);// wait for time=sensorvalue
  digitalWrite(LED2, HIGH);// turn on LED2
  digitalWrite(LED1, LOW);//turn off LED1
  sensorVal = analogRead(sensorPin);
  delay(sensorVal);// wait for time=sensorvalue       
  digitalWrite(LED3, HIGH);//turn on LED3
  digitalWrite(LED2, LOW);//turn off LED2
  sensorVal  = analogRead(sensorPin);
  delay(sensorVal);// wait for time=sensorvalue
  digitalWrite(LED4, HIGH);//turn on LED4 
  digitalWrite(LED3, LOW);//turn off LED3

button.loop();
if(button.isPressed())
Serial.println("1");

if(button.isReleased())
Serial.println("0");  //button pressed "1" button released "0" - serial print that number

//sensorVal = map(sensorVal, 0, 1023, 0, 255); - commented as it was considered but not needed. 
sensorVal = analogRead(sensorPin);
Serial.println(sensorVal);//serial print analog value
delay (analogRead(sensorPin) // wait for time=sensorvalue
}

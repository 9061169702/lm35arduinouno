/*    READ FIRST 
 * 
 * LM35 Library 
 * 
 * VERSION: 1.0.1
 * 
 * Author: Guilherme Gomes Zucco
 * 
 * This library set the pin where is the lm35 sensor,
 * and converts the raw value to Celsius or Fahrenheit or Kelvin.
 * 
 * Commands 
 * 
 * Set the pin with
 * LM35 name_of_variable(analog_pin);
 * exemple LM35 temp(A0);
 * 
 * shows the temperature wirh:
 * name_of_variable.cel() - to show the temperature in celsius
 * name_of_variable.fah() - to show the temperature in fahrenheit
 * name_of_variable.kel() - to show the temperature in kelvin
 * 
 * bellow has a example of code, enjoy;
*/
#include <LM35.h>

// setting the sensor in the pin A0
// Command - LM35 name_of_variable(analog_pin);
LM35 temp(A0);

// Define the onboard LED pin
const int ledPin = 13;  // Onboard LED pin connected to digital pin 13

//Variablw will change:
int ledstate = LOW;

//unsigned long for stroing time this can be longer than an int:
unsigned long previousMillis = 0; // will store the last time LED wasupdated
unsigned long currentMillis = 0;  // will store the time LED was active 

const long delay_long = 500; // delay of 500 miliseconds:
const long delay_short = 250; // delay of 250 miliseconds:

// Function that will be executed once when connecting or resetting the Arduino
void setup() 
{
  // start the Serial communication 
  Serial.begin(9600); 
   pinMode(ledPin, OUTPUT); // Set the LED pin as an output

}
 
// Function that will be executed continuously
void loop() {

 // Control the onboard LED based on temperature
 //get the temperature value in celsius 
  if (temp.cel()> 30.0) {

      currentMillis = millis();

      if(currentMillis - previousMillis >= delay_long){

        previousMillis = currentMillis;

        if(ledstate == LOW){
          ledstate = HIGH;
        } else {
          ledstate = LOW;
        }

        digitalWrite(ledPin, ledstate);
        
      }
    
  } else if(temp.cel()< 30.0){
    
      currentMillis = millis();

      if(currentMillis - previousMillis >= delay_short){

        previousMillis = currentMillis;

        if(ledstate == LOW){
          ledstate = HIGH;
        } else {
          ledstate = LOW;
        }

        digitalWrite(ledPin, ledstate);
        
      }
  }
}

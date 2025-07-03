/* The source Code from : https://github.com/riyadhasan24
 * By Md. Riyad Hasan
 */
 
const int Sensor = 2; // Digital pin 2 for the proximity sensor
const int Motor = 5;           // Digital pin 5 for the motor
const int Buzzer = 7;          // Digital pin 7 for the buzzer

unsigned long lowStateStartTime = 0; // Variable to store the time when the proximity sensor went LOW
const long requiredLowDuration = 3000; // 3 seconds in milliseconds

void setup() {
  pinMode(Sensor, INPUT); // Set the proximity sensor pin as an input
  pinMode(Motor, OUTPUT);         // Set the motor pin as an output
  pinMode(Buzzer, OUTPUT);        // Set the buzzer pin as an output

  // Ensure motor and buzzer are off initially
  digitalWrite(Motor, LOW);
  digitalWrite(Buzzer, LOW);

  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  int Sensor_Value = digitalRead(Sensor); // Read the state of the proximity sensor

  if (Sensor_Value == LOW) 
    {
      // If the sensor reads LOW, check if this is the start of a new LOW state
      if (lowStateStartTime == 0) 
        {
          lowStateStartTime = millis(); // Record the current time
          Serial.println("Proximity sensor went LOW. Starting timer.");
        }
  
      // Check if the LOW state has been maintained for the required duration
      if (millis() - lowStateStartTime >= requiredLowDuration) 
        {
          digitalWrite(Motor, HIGH);   // Turn the motor ON
          digitalWrite(Buzzer, HIGH);  // Turn the buzzer ON
          Serial.println("3 seconds of LOW detected. Motor and Buzzer HIGH.");
        }
    } 
  else 
  {
    // If the sensor reads HIGH, reset the timer and turn off motor/buzzer
    lowStateStartTime = 0; // Reset the timer
    digitalWrite(Motor, LOW);   // Turn the motor OFF
    digitalWrite(Buzzer, LOW);  // Turn the buzzer OFF
    Serial.println("Proximity sensor is HIGH. Motor and Buzzer LOW.");
  }
}

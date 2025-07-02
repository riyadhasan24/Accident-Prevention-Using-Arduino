#define Motor 4
#define Sensor 5
#define Buzzer 6

int Sensor_Value = 0;

void setup()
{
  pinMode(Motor, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Sensor, INPUT);

  digitalWrite(Motor, LOW);
  digitalWrite(Buzzer, LOW);
}

void loop()
{
  Sensor_Value = digitalRead(Sensor);

  if (Sensor_Value == LOW)
    {
      digitalWrite(Motor, HIGH);
      digitalWrite(Buzzer, HIGH);
    }

  else
    {
      digitalWrite(Motor, LOW);
      digitalWrite(Buzzer, LOW);
    }
}

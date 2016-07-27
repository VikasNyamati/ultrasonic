const int trigPin = 2;
const int echoPin = 4;

void setup() {
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  long duration, inches, cm;
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  analogWrite(9,250);
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  if(cm<10)
  {
    digitalWrite(11,HIGH);
    delay(1000);
    digitalWrite(11,LOW);
    delay(1000);
    if(cm<5)
  {
      motor_stop();
  }
  }     
  else
  {
    delay(100);
  }
  
}

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

void motor_stop()
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  analogWrite(9,0);
}


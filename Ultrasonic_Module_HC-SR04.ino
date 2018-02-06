#define MAX_DIST 23200

// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;

// defines variables
long pulse_with;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() 
{

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  pulse_with = pulseIn(echoPin, HIGH);
   
  if ( pulse_with > MAX_DIST ) 
  {
      Serial.println("Out of range");
  } 
  else 
  {
    // Calculating the distance in cm
    distance = pulse_with*0.034/2;
    
    // Prints the distance in cm
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  // Slow down 
  delay(100);
}

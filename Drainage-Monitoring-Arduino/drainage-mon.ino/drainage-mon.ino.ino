// defines pins numbers
const int trigPin1 = 9;
const int trigPin2 = 11;
const int trigPin3 = 13;

const int echoPin1 = 10;
const int echoPin2 = 6;
const int echoPin3 = 5;

// defines variables
long duration[3];
int distance[3];

void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(trigPin2, OUTPUT);
pinMode(trigPin3, OUTPUT);

pinMode(echoPin1, INPUT);
pinMode(echoPin2, INPUT);
pinMode(echoPin3, INPUT);// Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
void loop() {
// Clears the trigPin

digitalWrite(trigPin1, LOW);
digitalWrite(trigPin2, LOW);
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);

digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration[0] = pulseIn(echoPin1, HIGH);
distance[0] = duration[0]*0.034/2;

digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
duration[1] = pulseIn(echoPin2, HIGH);
distance[1] = duration[1]*0.034/2;


digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
delayMicroseconds(2);
duration[2] = pulseIn(echoPin3, HIGH);
distance[2] = duration[2]*0.034/2;

// Prints the distance on the Serial Monitor

Serial.print(distance[0]);
Serial.print(" ");
Serial.print(distance[1]);
Serial.print(" ");
Serial.print(distance[2]);
Serial.println("");
delay(3000);
}

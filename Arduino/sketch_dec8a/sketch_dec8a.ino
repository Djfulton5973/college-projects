#define trigPin 9
#define echoPin 10
#define led1 7
#define led2 6
#define led3 5
#define buzzer 3

int sound = 250;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzer, OUTPUT);

}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;


  if (distance <= 30) {
    digitalWrite(led1, HIGH);
    sound = 250;
}
  else {
    digitalWrite(led1,LOW);
  }

  if (distance < 15) {
      digitalWrite(led2, HIGH);
      sound = 260;
  }

  else {
      digitalWrite(led2, LOW);
      digitalWrite(led1, LOW);
  }

  if (distance < 5) {
      digitalWrite(led3, HIGH);
      sound = 270;
} 
  else {
    digitalWrite(led3, LOW);
  }

  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");
    noTone(buzzer);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);

  }
  delay(500);
}
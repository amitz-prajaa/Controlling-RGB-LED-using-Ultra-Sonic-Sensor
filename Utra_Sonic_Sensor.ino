const int triger = 8 ;
const int echo = 7 ;
long duration ;
int  distance ;

int  r= 7;   //  + ke right -> [ - - + R ]
int g = 6;   //  + ke left ->  [ - G + - ]
int b = 8;   //  + ke left ->  [ B - + - ]

void setup() {
  // put your setup code here, to run once:
      Serial.begin(9600);
      pinMode(triger , OUTPUT);
      pinMode(echo , INPUT);

      pinMode(r ,OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b , OUTPUT);
}

void loop() {

  // Clear the trigPin
  digitalWrite(triger, LOW);
  delayMicroseconds(2);

  // Set the trigPin high for 10 microseconds
  digitalWrite(triger, HIGH);
  delayMicroseconds(10);
  digitalWrite(triger, LOW);

  // Measure the echoPin duration
  duration = pulseIn(echo, HIGH);
      
  // Calculate the distance
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance<=10){
      digitalWrite(r , 0);
      digitalWrite(g, 1);
      digitalWrite(b,1);
  }
  else if(distance>10 && distance<=25){
      digitalWrite(r , 1);
      digitalWrite(g, 1);
      digitalWrite(b,0);
  }
  else{
      digitalWrite(r , 1);
      digitalWrite(g, 0);
      digitalWrite(b,1);
  }

  // Delay before the next measurement
  delay(500);
}

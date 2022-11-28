const int trigPin1 = 4;//right
const int echoPin1 = 5;
const int trigPin2 = 6; //left
const int echoPin2 = 7;
const int trigPin3 = 11;//center
const int echoPin3 = 12;
const int in1 = 3;
const int in2 = 2;
const int in3 = 8;
const int in4 = 13;
const int ENA = 9;
const int ENB = 10;



float duration_us1, distance_cm1,duration_us2, distance_cm2,duration_us3, distance_cm3;

void setup() {
  // begin serial port
  Serial.begin (9600);


  // configure the trigger pin to output mode
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);
  // configure the echo pin to input mode
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode (ENA, OUTPUT);
  pinMode (ENB, OUTPUT);

}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
 
  

  // measure duration of pulse from ECHO pin
     analogWrite(ENA,70);
    analogWrite(ENB,70);

  // calculate the distance

  //print the value to Serial Monitor
  print_distances();
  
  int front_dist;
  front_dist=FrontSensor();
  if(front_dist<=15 ){
    if(LeftSensor()>=15 && RightSensor()<=15){
      turn_left();
      delay(500);
      forward();

    
    }
    if(RightSensor()>=15){
      turn_left();
      delay(500);
      forward();

    }
    
    
  }
  else{
  forward();

  }
//     if(LeftSensor()<=5){
//     turn_left();
//     }

//     if(RightSensor(<= 5))
//     analogWrite(ENA,0);
//     analogWrite(ENB,0);
//     stop();
//     }
//   else {
//   analogWrite(ENA, 50);
//   analogWrite(ENB, 50);

//   }
//   if(LeftSensor()<=5){
//     turn_left();
//   }

     
  
  
  

}

long RightSensor ()
{
long dur;
digitalWrite(trigPin1, LOW);
delayMicroseconds(2); // delays are required for a succesful sensor operation.
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin1, LOW);
dur = pulseIn(echoPin1, HIGH);
return (dur/58);// convert the distance to centimeters.
}

long LeftSensor ()
{
long dur;
digitalWrite(trigPin2, LOW);
delayMicroseconds(2); // delays are required for a succesful sensor operation.
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin2, LOW);
dur = pulseIn(echoPin2, HIGH);
return (dur/58);// convert the distance to centimeters.
}

long FrontSensor ()
{
long dur;
digitalWrite(trigPin3, LOW);
delayMicroseconds(2); // delays are required for a succesful sensor operation.
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin3, LOW);
dur = pulseIn(echoPin3, HIGH);
return (dur/58);// convert the distance to centimeters.
}
void forward ()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}
void turn_left ()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

}
void turn_right ()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);

}
void reverse ()
{
Serial.print("Reversing\n");
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);

}
void stop()
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);

}

void print_distances()
{
  delay(1000);
  Serial.print("right distance1: ");
  Serial.print(RightSensor());
  Serial.println(" cm");
  Serial.print("left distance2: ");
  Serial.print(LeftSensor());
  Serial.println(" cm");
  Serial.print("front distance3: ");
  Serial.print(FrontSensor());
  Serial.println(" cm");
  Serial.println(" cm");
  

}




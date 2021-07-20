#define trig1 22 // pin declaration for ultrasonic sensor 1 
#define echo1 23

#define trig2 24 // pin declaration for ultrasonic sensor 2
#define echo2 25

#define trig3 26 // pin declaration for ultrasonic sensor 3
#define echo3 27

#define trig4 28 // pin declaration for ultrasonic sensor 4
#define echo4 29

#define trig5 30 // pin declaration for ultrasonic sensor 5
#define echo5 31

#define buzz 11 // pin declaration for buzzer

int s1, s2, s3, s4, s5; // proximity from respective ultrasonic sensor (s1 - s5) 

void setup() 
{
  Serial.begin(9600); // set up serial communication at 9600 baud

// I/O pin declaration 
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);

  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);

  pinMode(trig3, OUTPUT);
  pinMode(echo3, INPUT);

  pinMode(trig4, OUTPUT);
  pinMode(echo4, INPUT);

  pinMode(trig5, OUTPUT);
  pinMode(echo5, INPUT);

  pinMode(buzz, OUTPUT);
}

int proximity(int trig, int echo) // function to calculate the proximity of an object from a ultrasonic sensor
{
  digitalWrite(trig, LOW);
  delay(50);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echo, HIGH);
  return int(duration * 0.034 / 2);
}

int base_frequency(int s1, int s2, int s3, int s4, int s5, int s) 
  {// function to  select the base frequency based on the position of sensor with lowest proximity

    int adf = 0; // base frequency to play when individual ultrasonic sensor is trigerred without considering the proximity value
    if (s == s1) adf = 400;
    else if (s == s2) adf = 600;
    else if (s == s3) adf = 800;
    else if (s == s4) adf = 1000;
    else if (s == s5) adf = 1200;
    else (s == 0);
    return adf;
  }

void play(int s, int adf) // add proximity factor to base frequency and play the tone at that frequency
{
  if (s >= 5 && s < 10)
  {
    tone(buzz, adf); // play tone at adf frequency for 300 milliseconds
    delay(300);
    noTone(buzz); // stop playing the tone
  }
  else if (s >= 10 && s < 15)
  {
    tone(buzz, adf - 50);
    delay(300);
    noTone(buzz);
  }
  else if (s >= 15 && s < 20)
  {
    tone(buzz, adf - 100);
    delay(300);
    noTone(buzz);
  }
  else if (s >= 20 && s < 25)
  {
    tone(buzz, adf - 150);
    delay(300);
    noTone(buzz);
  }
  else tone(buzz, 0);
}

void loop()
{
  // get proximity from respective ultrasonic sensor
  s1 = proximity(trig1, echo1);
  s2 = proximity(trig2, echo2);
  s3 = proximity(trig3, echo3);
  s4 = proximity(trig4, echo4);
  s5 = proximity(trig5, echo5);

  int s = min(min(min(min(s1, s2), s3), s4), s5); // get minimum of all the proximity values
  int adf = base_frequency(s1, s2, s3, s4, s5, s); // calculate the base frequency
  Serial.println("s = " + String(s) + " and adf = " + String(adf)); // print s and adf to serial monitor
  play(s, adf); // play the tone

}

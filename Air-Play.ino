// Plays a tone as an object is moved above the ultrasonic sensor array

#define trig1 22
#define echo1 23

#define trig2 24
#define echo2 25

#define trig3 26
#define echo3 27

#define trig4 28
#define echo4 29

#define trig5 30
#define echo5 31

#define buzz 11

int s, s1, s2, s3, s4, s5, adf = 0;

void setup()
{
  Serial.begin(9600);

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

int sensor(int trig, int echo)
{
  digitalWrite(trig, LOW);
  delay(50);
  digitalWrite(trig, HIGH);
  delay(10);
  digitalWrite(trig, LOW);
  unsigned long duration = pulseIn(echo, HIGH);
  return int(duration * 0.034 / 2);
}

void get_data()
{
  s1 = sensor(trig1, echo1);
  s2 = sensor(trig2, echo2);
  s3 = sensor(trig3, echo3);
  s4 = sensor(trig4, echo4);
  s5 = sensor(trig5, echo5);
}

void play_me_hard(int s, int adf)
{
  if (s > 1)
  {
    tone(buzz, 500 + adf);
    delay(300);
    noTone(buzz);
    if (s > 15);
    {
      tone(buzz, 525 + adf);
      delay(300);
      if (s > 30);
      {
        tone(buzz, 550 + adf);
        delay(300);
        if (s > 45)
        {
          tone(buzz, 575 + adf);
          delay(300);
          if (s > 60 && s < 80)
          {
            tone(buzz, 600 + adf);
            delay(300);
          }
        }
      }
    }
  }
}

void loop()
{
  get_data();
  s = min(min(min(min(s1, s2), s3), s4), s5);
  Serial.println(s);
  if (s == s1)
  {
    adf = 0;
  }
  else if (s == s2)
  {
    adf = 100;
  }
  
  else if (s == s3) 
  {
    adf = 200;
  }
  else if (s == s4)
  {
    adf = 300;
  }
  else 
  {
    adf = 1000;
  }
  play_me_hard(s, adf);
}

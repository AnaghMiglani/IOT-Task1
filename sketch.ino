#define blue 11
#define green 10
#define red 9
#define button 2
int mode=0;
int on=0;
unsigned long t1;
unsigned long t0;
void setup() 
{
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  t0=millis();
}

void loop() 
{
  if (digitalRead(button) == LOW) 
      {
        mode = mode + 1;
        mode=mode%3;
        delay(400);
      }
  t1=millis();
  if ((t1-t0)>=1000)
  {
    if (on==0)
    {
      if (mode==0)
      {
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(blue, LOW);
      }
      if (mode==1)
      {
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(blue, LOW);
      }
      if (mode==2)
      {
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(blue, HIGH);
      }
      on=1;
    }
    else
    {
      digitalWrite(red, LOW);
      digitalWrite(green, LOW);
      digitalWrite(blue, LOW);
      on=0;
    }
    t0=millis();
  }
}

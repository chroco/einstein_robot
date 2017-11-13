
//Srijana Sapkota, Naser Alshami
//Group Homework Fall 2016
//Professor Marek Perkowski
//ECE478/578 Intelligent Robotics
//Effective Range: 10-80 cm 

//Code for implementing fuzzy logic 
//Our idea is to make neck move towards the obstacle based on infrared sensor distance inputs
// Outputs monitored using Serial Monitor tool in Arduino

#include <Servo.h>  // Servo library

//final crisp outputs for our robot

#define NECK_NEUTRAL 90
#define NECK_SLOW_LEFT 45
#define NECK_LEFT 20
#define NECK_SLOW_RIGHT 120
#define NECK_RIGHT 145

Servo N9;

char GP2D12; 
char GP2D12_b;
char a,b,x,y;
int rs_val;
int ls_val;

void setup()
{
 Serial.begin(9600); //baud rate is 9600
 N9.attach(9); //servo connected to head for our desired motion is named as N9 and is connected to digital pin 9 of arduino. 
}
void loop()
{

 GP2D12=read_gp2d12_range(0);
 a=GP2D12/10;
 b=GP2D12%10;
 rs_val=a*10+b;

 GP2D12_b=read_gp2d12_range(1);
 x=GP2D12_b/10;
 y=GP2D12_b%10;
 ls_val=x*10+y;

{
   Serial.print("Right Sensor: ");
   Serial.print(rs_val);
   Serial.print("cm - ");//
   Serial.print("Left  Sensor : ");
   Serial.print(ls_val);
   Serial.println("cm  ");//
}

//fuzzy implementation

  float rs_close, rs_medium, rs_far; //fuzzy inputs from right sensor
  float ls_close, ls_medium, ls_far; //fuzzy inputs from left sensor

  float sum_all_mins, sum_rotation_times_min;
  float final_fuzzy_output;
  float min1, min2, min3, min4, min5, min6, min7, min8, min9;

 //if else condition will take care of the conditions based on distance inputs
 //while ((ls_val >=10 || ls_val <=80) && (rs_val >=10 || rs_val <=80))
 //{
  if (rs_val <= 20)
  {
    rs_close = 1;
    rs_medium = 0;
    rs_far = 0;
  }
  else if (rs_val > 20 && rs_val < 40)
  {
    rs_close = (-rs_val/20.0) + 2.0;
    rs_medium = (rs_val/20.0) - 1.0;
    rs_far = 0;
  }
  else if (rs_val == 40)
  {
    rs_close = 0;
    rs_medium = 1;
    rs_far = 0;
  }
  else if (rs_val > 40 && rs_val < 60)
  {
    rs_close = 0;
    rs_medium = (-rs_val/20.0) + 3.0;
    rs_far = (rs_val/20.0) - 2.0;
  }
  else if (rs_val >= 60)
  {
    rs_close = 0;
    rs_medium = 0;
    rs_far = 1;
  }

   if (ls_val <= 20)
  {
    ls_close = 1;
    ls_medium = 0;
    ls_far = 0;
  }
  else if (ls_val > 20 && ls_val < 40)
  {
    ls_close = (-ls_val/20.0) + 2.0;
    ls_medium = (ls_val/20.0) - 1.0;
    ls_far = 0;
  }
  else if (ls_val == 40)
  {
    ls_close = 0;
    ls_medium = 1;
    ls_far = 0;
  }
  else if (ls_val > 40 && ls_val < 60)
  {
    ls_close = 0;
    ls_medium = (-rs_val/20.0) + 3.0;
    ls_far = (rs_val/20.0) - 2.0;
  }
  else if (ls_val >= 60)
  {
    ls_close = 0;
    ls_medium = 0;
    ls_far = 1;
  }
  

  //Serial.print(rs_close, rs_medium, rs_far, ls_close, ls_medium, ls_far, F, DEC, DEC, DEC);
   Serial.println("Reading");
   Serial.println(rs_close);
   Serial.println(rs_medium);
   Serial.println(rs_far);
   Serial.println(ls_close);
   Serial.println(ls_medium);
   Serial.println(ls_far);
   
    min1 = min(ls_close, rs_close);
    min2 = min(ls_close, rs_medium);
    min3 = min(ls_close, rs_far);
    min4 = min(ls_medium, rs_close);
    min5 = min(ls_medium, rs_medium);
    min6 = min(ls_medium, rs_far);
    min7 = min(ls_far, rs_close);
    min8 = min(ls_far, rs_medium);
    min9 = min(ls_far, rs_far);

    sum_all_mins = min1+min2+min3+min4+min5+min6+min7+min8+min9;

    if(sum_all_mins !=0)
    {
    sum_rotation_times_min = (min1 *NECK_NEUTRAL) + (min2 * NECK_SLOW_LEFT) + (min3 * NECK_LEFT) + (min4 * NECK_SLOW_RIGHT) + (min5 * NECK_NEUTRAL) + (min6 * NECK_SLOW_LEFT) + (min7 * NECK_RIGHT) + (min8 * NECK_SLOW_RIGHT) + (min9 * NECK_NEUTRAL);

    final_fuzzy_output = sum_rotation_times_min/sum_all_mins;
    Serial.println("heree is it");
    Serial.println(final_fuzzy_output);
    }
    N9.write(final_fuzzy_output);
    delay (1000);
 //} 
}
//this code reads in sensor inputs 
//obtained from internet
float read_gp2d12_range(byte pin)
{
 int tmp;
 tmp = analogRead(pin);
 if (tmp < 3)return -1;
  return (6787.0 /((float)tmp - 3.0)) - 4.0;
}

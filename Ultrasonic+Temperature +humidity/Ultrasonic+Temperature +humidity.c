#include<dht11.h>
dht11 DHT11;
#define DHT11PIN 4


const int TrigPin=2;
const int EchoPin=3;

float distance;
float speed;
int humidity=DHT11.humidity;
int temperature=DHT11.temperature;


float get_times()
{

float sr_time=0;

digitalWrite(TrigPin,LOW);
delay(1);
digitalWrite(TrigPin,HIGH);
delay(1);
digitalWrite(TrigPin,LOW);
sr_time=pulseIn(EchoPin,HIGH);
sr_time=sr_time/1000/1000;  //��ȡʱ��
return sr_time;
}


void setup()
{
    Serial.begin(9600); //���ò�����9600
    Serial.println("----Starting----");
    pinMode(TrigPin,OUTPUT);
    pinMode(EchoPin,INPUT);
    Serial.println("Ultrasonic sensor:");
}
void loop()
{
    Serial.println("\n");
    int chk = DHT11.read(DHT11PIN);

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK:
                Serial.println("OK");
                break;
    case DHTLIB_ERROR_CHECKSUM:
                Serial.println("Checksum error");
                break;
    case DHTLIB_ERROR_TIMEOUT:
                Serial.println("Time out error");
                break;
    default:
                Serial.println("Unknown error");
                break;
  }

    Serial.print("----Data----");
    float time=get_times();
    if (temperature<=10)
    {
    speed=331.56+0.61*temperature;
    }
    while(temperature>10&&temperature<20)
    {
        if(humidity>10&&humidity<=20)
        {
            speed=339.99;
        }
        if(humidity>20&&humidity<=30)
            {
                speed=340.07;
            }
        if(humidity>30&&humidity<=40)
            {
                speed=340.17;
            }
        if(humidity>40&&humidity<=50)
            {
                speed=340.26;
            }
        if(humidity>50&&humidity<=60)
            {
                speed=340.32;
            }
        if(humidity>60&&humidity<=70)
            {
                speed=340.45;
            }
        if(humidity>70&&humidity<=80)
            {
                speed=340.54;
            }
        if(humidity>80&&humidity<=90)
            {
                speed=340.63;
            }
        if(humidity>90&&humidity<=100)
            {
                speed=340.73;
            }
    }

    distance=(speed*time)/2.0;
    Serial.print("Humidity (%): ");
    Serial.println((float)DHT11.humidity, 4);
    Serial.print("Temperature (oC): ");
    Serial.println((float)DHT11.temperature, 4);
    Serial.print(distance);
    Serial.print("cm");
    Serial.println();
    delay(1000);
}

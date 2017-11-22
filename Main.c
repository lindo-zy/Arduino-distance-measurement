#include<DHT.h>
#include<LiquidCrystal_I2C.h>
#include<Wire.h>

LiquidCrystal_I2C lcd(0x27,16,2);

#define DHTTYPE DHT11
#define DHTPIN 4

DHT dht(DHTPIN,DHTTYPE);
const int TrigPin=2;
const int EchoPin=3;

float distance;
float vspeed;
//float humidity=dht.readHumidity();
//float temperature=dht.readTemperature();

float sr_time=0;

void setup()
{
    Serial.begin(9600); //
    dht.begin();
    pinMode(TrigPin,OUTPUT);
    pinMode(EchoPin,INPUT);
    Serial.println("-----Begining------:");
    lcd.init();
    lcd.backlight();
}
void loop()
{
    delay(2000);
   float humidity=dht.readHumidity();
 float temperature=dht.readTemperature(); 


 
    
    digitalWrite(TrigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin,LOW);   //�������


    sr_time=pulseIn(EchoPin,HIGH);
    sr_time=sr_time/1000/1000;  //�����s



 

    if (temperature<=10)
    {
    vspeed=331.56+0.61*temperature;
    }
    if(temperature>10)
    {
        if(humidity>10&&humidity<=20)
        {
            vspeed=339.99;
        }
        if(humidity>20&&humidity<=30)
            {
                vspeed=340.07;
            }
        if(humidity>30&&humidity<=40)
            {
                vspeed=340.17;
            }
        if(humidity>40&&humidity<=50)
            {
                vspeed=340.26;
            }
        if(humidity>50&&humidity<=60)
            {
                vspeed=340.32;
            }
        if(humidity>60&&humidity<=70)
            {
                vspeed=340.45;
            }
        if(humidity>70&&humidity<=80)
            {
                vspeed=340.54;
            }
        if(humidity>80&&humidity<=90)
            {
                vspeed=340.63;
            }
        if(humidity>90&&humidity<=100)
            {
                vspeed=340.73;
            }
    }

    distance=((vspeed*sr_time)/2.0)*1000;
    Serial.print("Humidity (%): ");
    Serial.println(humidity);
    Serial.print("Temperature (oC): ");
    Serial.println(temperature);
    Serial.print(distance,4);
    Serial.print("mm");
    Serial.println();
    Serial.print(sr_time,8);
    if(distance>0)
    {
    lcd.clear();
    lcd.print("dis:");
    lcd.print(distance,4);
    lcd.println("mm");
    lcd.setCursor(0,1);
    lcd.print("T:");
    lcd.print((int)temperature);
    lcd.print("c");
    lcd.print("  ");
    lcd.print("H:");
    lcd.print((int)humidity);
    lcd.print("%");
    }
    
    else
    {
        lcd.clear();
        lcd.print("No Data!!!");
        
    }
     
    delay(2000);
}


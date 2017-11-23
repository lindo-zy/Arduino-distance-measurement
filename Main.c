#include<DHT.h>      //引入DHT11头文件
#include<LiquidCrystal_I2C.h>   //1602 I2C 头文件
#include<Wire.h>
#include<Servo.h>       //舵机头文件
LiquidCrystal_I2C lcd(0x27,16,2);       // lcd(串口，字符串大小，2行)

#define DHTTYPE DHT11
#define DHTPIN 4                //DHT11  定义为4引脚

DHT dht(DHTPIN,DHTTYPE);
Servo myservo;

const int TrigPin=2;            //超声波 Trig 引脚为2
const int EchoPin=3;            //超声波 Echo 引脚为3

float distance;                  //距离
float vspeed;                   //声音速度
float sr_time=0;                //超声波接收时间
int pos=0;                      //转动角度



void fun()                      //主体函数模块
{
  
     delay(2000);               //dht11 需要延迟2S 进行工作
    Serial.println("\n");
    float humidity=dht.readHumidity();
    float temperature=dht.readTemperature(); 
    digitalWrite(TrigPin,LOW);      //启动超声波模块
    delayMicroseconds(2);
    digitalWrite(TrigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin,LOW);   
    

    sr_time=pulseIn(EchoPin,HIGH);      //获取超声波收发时间
    sr_time=sr_time/1000/1000;       //单位转换为s

    if (temperature<=10)            //声音速度修正
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

    distance=((vspeed*sr_time)/2.0)*1000;           //来回时间除2为距离，单位为毫米
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
    

    Serial.println("\n");
    Serial.print("pos:");
    Serial.print(pos);
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
  
  
  
  }


void setup()
{
    Serial.begin(9600);     // 设置波特率为9600
    Serial.println("-----Begining------:");
    myservo.attach(9);      //设置舵机 引脚为9 （舵机只能用9，10口）
    dht.begin();
    pinMode(TrigPin,OUTPUT);
    pinMode(EchoPin,INPUT);
    
    lcd.init();             //lcd初始化
    lcd.backlight();        //lcd背光



}
void loop()
{

    for(pos=0;pos<=180;pos+=30) //从0-180每次转30度
    {

    myservo.write(pos);
    fun();


    }

    for(pos=180;pos>=0;pos-=30)  //从180-0每次转30度
    {
        myservo.write(pos);
        fun();



    }


    delay(2000);     //延迟和DHT11同步


    
    
}


# Arduino-distance measurement
基于Arduino的超声波测距项目  
---  
* 设计思路：  
使用超声波和舵机，探测物体的方向和距离，并使用温湿度模块修正数据。后期可能加入wifi模块进行数据传输。
---  
* 所需硬件  
1.USB转TTL  
2.5v继电器  
3.3个led彩灯  
4.SG90  9g舵机  
5.杜邦线  
6.usb线  
7.DHT11 温度湿度模块  
8.HC-SR04超声波模块  
9.面包板+电源模块  
10.ESP-8266 wifi模块  
11.arduino uno R3板  
12.220欧姆电阻    
13.公母线   
14.1602A l2c显示屏  
15.DC电源线
---  
* 软件平台  
Arduino IDE  
Arduino Box  
windows10  /Ubuntu 17.10

----
* 头文件使用方法  
DHT11头文件，DHT.h和DHT.cpp，在Arduino安装目录下的libraries文件夹下，新建Dht11。  
LCD头文件，LiquidCrystal_I2C.h和LiquidCrystal_I2C.cpp，在Arduino安装目录下的libraries文件夹下，新建iquidCrystal_I2C。

---
* 本实验接线说明  
1.Arduino不提供电源，只提供引脚，USB供电  
2.面包板需要电源模块供电，DC线供电  
3.SR04 超声波模块，Trig=2，Echo=3，电源5v，接地  
4.DHT11 温湿度模块，DTHPIN=4，电源5v，接地（不可接反，否则烧毁Arduino板）  
5.LCD 1602A I2C显示屏，SDA=A4，ACL=A5，电源5v，接地  
6.SG90 舵机模块，attach=9,电源5v，接地  
---
* 实验数据说明  
超声波的传播大体受三个因素影响，介质，温度，湿度。本次实验在空气中进行，地点上海，海拔几乎为海平面，不考虑压强影响。当温度在10度以下时，湿度对
声音的传播影响极小，v=331.56+0.61*temperature；当温度大于10度时，湿度对声音传播速度影响明显，我们取10%到100%湿度的数据的平均值。最终实验结果精确到了以毫米为单位，小数点后四位。
![实验数据截图](https://raw.githubusercontent.com/xiao-yi/Arduino-wifi-waves/master/data.png)
---
* 实验误差分析
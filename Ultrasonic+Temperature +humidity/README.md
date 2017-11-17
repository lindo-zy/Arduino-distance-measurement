# 超声波 温度湿度 模块
超声波模块为 HC-SR04  
温湿度模块为 DHT11  
---
超声波模块引脚为 TrigPin=2  EchoPin=3  
温湿度模块引脚为 DHT11PIN=4  
温湿度模块需要引入头文件，放在arduino的安装目录的libraries的Dht11文件夹下，头文件命名为dht11
```c
//头文件
#ifndef dht11_h
#define dht11_h

#if defined(ARDUINO) && (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define DHT11LIB_VERSION "0.4.1"

#define DHTLIB_OK				0
#define DHTLIB_ERROR_CHECKSUM	-1
#define DHTLIB_ERROR_TIMEOUT	-2

class dht11
{
public:
    int read(int pin);
	int humidity;
	int temperature;
};
#endif
//
// END OF FILE
//


```
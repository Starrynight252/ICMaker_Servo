/*
 使舵机旋转，从0度到90度，然后返回0度，然后返回90度，依此类推。

 创建于2025/02/14
 作者：ICROBOT

*/

// 包含ESP32 Arduino Servo库，而不是原始Arduino Servo库
#include <ICMaker_Servo.h>

Servo myservo; // 创建一个舵机对象来控制一个舵机

// ESP32 上可能的 PWM GPIO 引脚：0（用于板载按钮）、2、4、5、12-19、21-23、25-27、32-33
// ESP32-S2 上可能的 PWM GPIO 引脚：0（用于板载按钮）、1-17、18、19-21、26、33-42
// ESP32-S3 上可能的 PWM GPIO 引脚：0（用于板载按钮）、1-21、35-45、47、48
// ESP32-C3 上可能的 PWM GPIO 引脚：0（用于板载按钮）、1-7、8、9-10、18-21
int servoPin = 18; // GPIO pin used to connect the servo control (digital out)

void setup()
{
    myservo.begin(servoPin); // 简洁初始化，只需要引脚号，最大最小值分别为544和2400，频率为50Hz
}

void loop()
{

    myservo.write(0);  // 舵机转到0度
    delay(1000); // 等待1秒
    myservo.write(90); // 舵机转到90度
    delay(1000);    // 等待1秒
}

# ESP32的舵机库

专为Arduino ESP32的V3.0.0版本设计。所有ADC都已更新以正确工作于新版本。

https://github.com/espressif/arduino-esp32/releases

该库尝试忠实地复制Arduino舵机库（参见http://www.arduino.cc/en/Reference/Servo）的语义，适用于ESP32，并增加了两个（可选）功能。这两个新功能暴露了ESP32 PWM定时器改变定时器宽度的能力。
# 由Doxygen生成的文档

[ESP32Servo Doxygen](https://madhephaestus.github.io/ESP32Servo/annotated.html)

## 许可证

版权所有 (c) 2017 John K. Bennett。保留所有权利。

该库是自由软件；您可以根据GNU较小通用公共许可证的条款重新分发和/或修改它；该许可证由自由软件基金会发布，许可证版本为2.1或（根据您的选择）任何更高版本。

该库的发布目的是希望它能有用，但不提供任何担保；甚至没有适销性或特定用途适用性的隐含担保。有关详细信息，请参阅GNU较小通用公共许可证。

您应该已经随该库一起收到了GNU较小通用公共许可证的副本；如果没有，请写信给自由软件基金会，地址是：51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

## 库描述：
```
    Servo - 用于操作连接到ESP32引脚的舵机的类。
    
    添加简洁方法(可看SimpleServoControl例程)：
    1.使用简洁初始化void begin(int pin); 并且设置gio
    2.使用void write(角度);

    原介绍:
    int attach(pin )  - 将给定的GPIO引脚连接到下一个空闲通道
        （优先使用先前已分离的通道），返回通道号或0（如果失败）。所有引脚号都允许，
        但仅推荐使用引脚2,4,12-19,21-23,25-27,32-33。
    
    int attach(pin, min, max  ) - 连接到一个引脚，设置最小和最大
        微秒值；强制最小值为500，强制最大值为2500。其他语义与attach()相同。
    
    void write () - 设置舵机角度（以度为单位）；小于500的值
        被视为度数值（0到180）。这些限制是强制的，即，值被约束如下：
            值                                     变为
            -----                                   -------
            < 0                                        0
            0 - 180                                  值（视为度数）
            181 - 499                                 180
            500 - (min-1)                             min
            min-max（来自attach或默认）         值（视为微秒）
            (max+1) - 2500                            max
    
    void writeMicroseconds() - 设置舵机脉冲宽度（以微秒为单位）。
        强制执行最小值和最大值（见上文）。 
        
    int read() - 获取最后写入的舵机脉冲宽度（以0到180度之间的角度表示）。 
    
    int readMicroseconds()   - 获取最后写入的舵机脉冲宽度（以微秒为单位）。
    
    bool attached() - 如果该舵机实例连接到引脚，则返回true。
    
    void detach() - 停止连接的舵机，释放连接的引脚，并释放
        其通道以供重用。  
```

### **新的ESP32特定功能**
 
```
原描述:
    setTimerWidth(value) - 设置PWM定时器宽度（必须为16-20）（仅限ESP32）；
        作为副作用，脉冲宽度将重新计算。

    int readTimerWidth() - 获取PWM定时器宽度（仅限ESP32） 
添加:
void begin(int pin); 和 void begin(int pin, int min, int max);
并且把
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
    放入在begin,只是方便使用，也保留了原来库方法。
```
 
### 有用的默认值：
begin(int pin) 最大最小值分别为544和2400 频率为50Hz
begin(int pin, int min, int max) 频率为50Hz

attach()的默认最小脉冲宽度：544us

attach()的默认最大脉冲宽度：2400us

默认定时器宽度16（如果未设置定时器宽度）

默认脉冲宽度1500us（舵机以此值初始化）

最小脉冲宽度：500us

最大脉冲宽度：2500us

最大舵机数量：16（这是ESP32中的PWM通道数量）
# ESP32-S3-AmourK08-4Keys
AmourK08 Speaker With 4 keys and TF card powered by ESP32-S3

# Details
1. ESP32-S3-AmourK08-4Keys is a speaker with 4 keys and TF card powered by ESP32-S3.
![image](https://cdn.jsdelivr.net/gh/zhuhai-esp/ESP32-S3-AmourK08-4Keys@master/Documents/face.png)
![image](https://cdn.jsdelivr.net/gh/zhuhai-esp/ESP32-S3-AmourK08-4Keys@master/Documents/back.png)
![image](https://cdn.jsdelivr.net/gh/zhuhai-esp/ESP32-S3-AmourK08-4Keys@master/Documents/sch.png)

2. 电路详情
* 硬件(并不是最新)：[ESP32-S3-AmourK08-4Keys硬件开源地址](https://oshwhub.com/hzy3774/esp32s3-gai-zhuang-armourk08-lan-ya-yin-xiang-tf-ka-4-jian-ban)
* 最新硬件请参考电路图和PCB：[ESP32-S3-AmourK08-4Keys GitHub](https://github.com/zhuhai-esp/ESP32-S3-AmourK08-4Keys/releases/)
* 或者 [ESP32-S3-AmourK08-4Keys Gitee](https://gitee.com/zhuhai-esp/ESP32-S3-AmourK08-4Keys/releases)

3. 配件详情：
* 主控：ESP32-S3
* 音频：MAX98357
* 电池管理：IP5306
* 3.3V稳压：Asm1117
* 氛围灯：WS2812B
* 温湿度传感器：AHT20
* 陀螺仪：MPU6050
* 屏幕：ST7789 1.3寸IPS

4. 交流反馈
* QQ交流群1：1034289371

# 小智相关
1. 程序编译
    * 代码：https://github.com/78/xiaozhi-esp32
    * 编译说明：[小智 AI 聊天机器人百科全书](https://ccnphfhqs21z.feishu.cn/wiki/F5krwD16viZoF0kKkvDcrZNYnhb)

2. 定制化修改
由于电路设计与官方小智接线不一致，所以需要修改部分引脚定义(config.h)
如有其他变动请参考电路原理图
``` c
// 音频相关
#define AUDIO_I2S_METHOD_SIMPLEX

#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_41
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_39
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_40
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_5
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_6
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_7

// 按钮及LED
#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_NC
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_9
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_21

// 显示相关
#define DISPLAY_BACKLIGHT_PIN GPIO_NUM_15
#define DISPLAY_MOSI_PIN      GPIO_NUM_18
#define DISPLAY_CLK_PIN       GPIO_NUM_8
#define DISPLAY_DC_PIN        GPIO_NUM_16
#define DISPLAY_RST_PIN       GPIO_NUM_17
#define DISPLAY_CS_PIN        GPIO_NUM_NC

#define DISPLAY_WIDTH   240
#define DISPLAY_HEIGHT  240
#define DISPLAY_MIRROR_X false
#define DISPLAY_MIRROR_Y true
#define DISPLAY_SWAP_XY true
#define DISPLAY_INVERT_COLOR    true
#define DISPLAY_RGB_ORDER  LCD_RGB_ELEMENT_ORDER_RGB
#define DISPLAY_OFFSET_X  80
#define DISPLAY_OFFSET_Y  0
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false
```

3. 固件烧录
可以参考小智官方文档，使用在线烧录方式比较方便：
* 在线烧录网址：https://espressif.github.io/esp-launchpad/


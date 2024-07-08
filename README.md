![img](https://cdn-shop.adafruit.com/970x728/1138-00.jpg)

[![YouTube Channel Views](https://img.shields.io/youtube/channel/views/UCz5BOU9J9pB_O0B8-rDjCWQ?label=YouTube&style=social)](https://www.youtube.com/watch?v=tQJWNoRK7sc)

# 막대 조명 만들기

프로그램 가능한 LED를 활용하여 조명만들어보기

#### [프로그램 가능한 LED란?](/doc/aboutNeoPixel.md)

# 하드웨어 

- 아두이노 우노  
- [WS2813 RGB LED 스트립 30LED/ 1m](https://vctec.co.kr/product/detail.html?product_no=13996)
- M-M 점퍼선 6개 
- USB 2.0 케이블 Type A/B
- [조도센서 모듈](https://www.devicemart.co.kr/goods/view?no=1287124) 


**주의: 점퍼선 연결시 케이블을 제거하고 진행합니다.**

# 회로도
![schematic](/img/schematic_v1.png)

## 선 작업 

| [Arduino UNO GPIO](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf) | WS2813  |
|-----------|------|
|   D8     | DI  |
|   5V      | 5V  |
|   GND     | GND  |

* WS2813은 데이터를 직렬로 전달합니다. 즉, 첫 번째 LED가 데이터를 받아 처리한 후 나머지 데이터를 다음 LED로 전달합니다.

| [Arduino UNO GPIO](https://docs.arduino.cc/resources/pinouts/A000066-full-pinout.pdf) | 조도센서  |
|-----------|------|
|   A0     | OUT  |
|   VCC    | 5V   |
|   GND    | GND  |

## 라이브러리  
1. [AdafruitNeopixel](https://github.com/adafruit/Adafruit_NeoPixel)  
: Adafruit NeoPixel 라이브러리는 WS2813와 같은 개별 주소 지정이 가능한 RGB LED를 쉽게 제어할 수 있게 해주는 라이브러리입니다. 이 라이브러리를 사용하면 여러 개의 LED를 연결하고 각각의 색상을 개별적으로 제어할 수 있습니다.

# 함수 
1. setPixelColor(n,red, green, blue): LED의 색상을 설정하는 함수
   - n: LED의 인덱스 
   - red, green, blue: 각 색상 채널의 강도 (0-255)

2. strip.show() : LED 색상을 변경하는 함수 



## 응용하기
1. 무드등 효과를 내도록하기
2. 캠프파이어 효과를 내도록 하기




# 라이센스 
[GPL 3.0](https://olis.or.kr/license/Detailselect.do?lId=1072&mapCode=010072)

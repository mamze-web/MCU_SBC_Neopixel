#include <Adafruit_NeoPixel.h>

// Adafruit_NeoPixel 라이브러리: LED 스트립을 쉽게 제어할 수 있게 해주는 라이브러리입니다.

// 네오픽셀을 연결한 핀과 네오픽셀 개수 정의
#define LED_PIN 8
#define LED_COUNT 30

// Adafruit_NeoPixel 라이브러리를 사용하여 네오픽셀 객체 생성
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// setup 함수: 프로그램이 시작될 때 한 번만 실행됩니다.
void setup() {
    // 네오픽셀 초기화
    strip.begin();
    strip.show(); // 모든 픽셀을 '꺼진' 상태로 초기화

    // 시리얼 통신 시작 (데이터 확인을 위해)
    Serial.begin(9600);
}

// loop 함수: setup 함수 이후 계속해서 반복 실행됩니다.
void loop() {
    // A0 핀의 아날로그 값 읽기 (예: 조도 센서)
    int sensorValue = analogRead(A0);
    
    // 센서 값을 시리얼 모니터에 출력
    Serial.println(sensorValue);
    
    // 센서 값에 따라 LED 색상 변경
    if (sensorValue < 500) {
        colorFill(strip.Color(0, 255, 0)); // 초록색으로 네오픽셀을 채움
    } else {
        colorFill(strip.Color(0, 0, 0)); // LED를 끔 (검은색)
    }
    
    delay(100); // 0.1초 대기 (너무 빠른 반복을 방지)
}

// 지정된 색으로 모든 네오픽셀을 채우는 함수 
void colorFill(uint32_t color) {
    for (int i = 0; i < strip.numPixels(); i++) {
        strip.setPixelColor(i, color); // i번째 네오픽셀의 색을 설정
    }
    strip.show(); // 변경된 색상을 네오픽셀에 표시
}
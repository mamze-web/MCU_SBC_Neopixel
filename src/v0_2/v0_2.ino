#include <Adafruit_NeoPixel.h>

#define LED_PIN 8
#define LED_COUNT 30
#define SENSOR_PIN A0

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

int brightness = 0;  // 현재 밝기
int fadeAmount = 5;  // 밝기 변화량

void setup() {
    strip.begin();
    strip.show();  // 모든 픽셀을 '꺼진' 상태로 초기화
    Serial.begin(9600);  // 디버깅을 위한 시리얼 통신 시작
}

void loop() {
    int sensorValue = analogRead(SENSOR_PIN);
    Serial.println(sensorValue);  // 센서 값 출력

    if (sensorValue <= 500) {
        // 조도가 낮을 때 (어두울 때) LED를 켭니다
        brightness = min(brightness + fadeAmount, 255);
    } else {
        // 조도가 높을 때 (밝을 때) LED를 끕니다
        brightness = max(brightness - fadeAmount, 0);
    }

    setAllLEDs(getColor(brightness));
    strip.show();

    delay(30);  // 약간의 지연으로 부드러운 변화 효과
}

// 현재 밝기에 따른 색상을 반환하는 함수
uint32_t getColor(int brightness) {
    // 여기서 원하는 색상을 정의합니다.
    // 예: 따뜻한 흰색
    return strip.Color(brightness, brightness * 0.8, brightness * 0.5);
}

// 모든 LED를 지정된 색상으로 설정하는 함수
void setAllLEDs(uint32_t color) {
    for (int i = 0; i < LED_COUNT; i++) {
        strip.setPixelColor(i, color);
    }
}

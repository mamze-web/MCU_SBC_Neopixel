#include <Adafruit_NeoPixel.h>

// 네오픽셀을 연결한 핀과 네오픽셀 개수 정의
#define LED_PIN 8
#define LED_COUNT 30

// Adafruit_NeoPixel 라이브러리를 사용하여 네오픽셀 객체 생성
Adafruit_NeoPixel strip(LED_COUNT , LED_PIN, NEO_GRB + NEO_KHZ800);

// 초기 설정
void setup(){
    // 네오픽셀 초기화
    strip.begin();

    // 네오픽셀 초기화 후 모든 네오픽셀을 끔
    strip.show();

    // 네오픽셀 밝기 설정 (0 ~ 255 범위)
    strip.setBrightness(50); // 50% 밝기
}

// 메인 루프
void loop(){
    // colorWipe 함수 호출하여 빨간색으로 네오픽셀을 채우는 효과 생성
    colorWipe(strip.Color(255, 0 , 0), 50); // 빨간색, 50ms 딜레이

    // rainbow 함수 호출하여 네오픽셀에 무지개 효과 생성
    //rainbow(10); // 10ms 딜레이
}

// 지정된 색으로 네오픽셀을 채우는 함수
void colorWipe(uint32_t color, int wait){
    for (int i = 0; i < strip.numPixels(); i++){
        strip.setPixelColor(i, color); // i번째 네오픽셀의 색을 설정

        strip.show(); // 변경된 색상을 네오픽셀에 표시

        delay(wait); // 설정한 시간만큼 대기
    }
}

// 무지개 효과를 생성하는 함수
void rainbow(int wait) {  
    // 모든 네오픽셀에 대해 무지개 색상을 계산하여 설정
    for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
        for (int i = 0; i < strip.numPixels(); i++) { 
            // 네오픽셀 위치에 따라 무지개 색상 결정
            int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());      
            strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
        }
        strip.show(); // 변경된 색상을 네오픽셀에 표시
        delay(wait); // 설정한 시간만큼 대기
    }
}

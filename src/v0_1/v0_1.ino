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

    // 시리얼 통신 시작
    Serial.begin(9600);
}

// 메인 루프
void loop(){
    int readValue = analogRead(A0); // A0 핀의 아날로그 값 읽기
    Serial.println(readValue); // 시리얼 모니터에 출력
    if (readValue < 500) {
	colorFill(strip.Color(0, 255, 0)); // 초록색으로 네오픽셀을 채움
    }
    else {
	colorFill(strip.Color(0, 0, 0)); // 초록색으로 네오픽셀을 채움
    }
}

// 지정된 색으로 네오픽셀을 한번에 채우는 함수 
void colorFill(uint32_t color){
    for (int i = 0; i < strip.numPixels(); i++){
	strip.setPixelColor(i, color); // i번째 네오픽셀의 색을 설정
    }
    strip.show(); // 변경된 색상을 네오픽셀에 표시
}




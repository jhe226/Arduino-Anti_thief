/*
Designed by CanIT
https://canduino.kr
*/

int trigPin = 4;  // 초음파센서 Trig 연결핀
int echoPin = 3;  // 초음파센서 Echo 연결핀

int ledPin = 12;  // LED +극 연결핀

int piezoPin = 9;  // 피에조스피커 +극 연결핀

int standard = 10;  // 기준 거리 변수. 이 길이보다 물체가 멀어지면 도난으로 인식

void setup() {
  // 핀모드를 설정합니다
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(ledPin, OUTPUT);
  
  pinMode(piezoPin, OUTPUT);
  Serial.begin(9600); // 시리얼 통신 시작
}

void loop() {
  // 초음파센서로 거리를 측정합니다.
  // 아래서 사용한 거리측정 코드는 HC-SR04 초음파센서 메뉴얼에 있는 대로 작성한 것입니다.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int distance = pulseIn(echoPin, HIGH) / 58;   // cm로 변환하기 위해 58로 나눔. 메뉴얼에 있는 내용입니다
  Serial.println(distance);   // 시리얼 모니터에 측정거리 출력

  // 측정된 거리가 기준 거리보다 크거나 같으면 LED, 피에조스피커 작동
  if (distance >= standard) {
    tone(piezoPin, 262, 500);   // 사용법 : 핀, 음의 주파수(높낮이), 음의 지속시간
    digitalWrite(ledPin, HIGH);
    delay(1000);
    noTone(piezoPin);
    digitalWrite(ledPin, LOW);
  }
}

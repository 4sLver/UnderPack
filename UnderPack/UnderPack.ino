#include <Servo.h>

//定义Trig,Echo,servo引脚
int trigPin = 6;
int echoPin = 5;
int servoPin = 7;

int pos = 0;

//定义舵机对象
Servo servo;

void setup() {
  //将舵机引脚赋予servo
  servo.attach(servoPin);

  //设置trig,echo的状态
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  //用10微秒脉冲测距
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int distance = pulseIn(echoPin, HIGH);
  distance = distance/58;
  Serial.println(distance);
  delay(300);

  //通过超声波测距判断是否有物体
  if (distance<=10) {
    for (pos = 0; pos <= 150; pos += 150) {
      servo.write(10);
      delay(15);
    }
  }
  if (distance>=10) {
    for (pos = 180; pos >= 0; pos -= 180) {
      servo.write(150);
      delay(15);
    }
  }
}

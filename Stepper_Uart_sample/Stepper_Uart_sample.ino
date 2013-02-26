#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200
Stepper stepper(STEPS, 4, 5, 6, 7);
Stepper stepper2(STEPS, 7, 6, 5, 4);

void setup()
{
  //シリアル通信開始
  Serial.begin(9600);
  stepper.setSpeed(30);
  stepper2.setSpeed(30);
}

void loop()
{
  if (Serial.available() > 0) { // シリアル通信でデータが送られてくるまで待つ。
    char c = Serial.read(); // 一文字分データを取り出す。
    if (c == 'n') { // nが送られてきたら正転させる。
      stepper.step(50);
    } else if(c == 'f') { // fが送られてきたら逆転させる。
      stepper2.step(50);
    }
  }
  
}

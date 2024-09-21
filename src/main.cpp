#include <mbed.h>
#include "pins.hpp"
#include "parameters.hpp"
#include "driveMotor/driveMotor.hpp"
// モータの設定
DriveMotor motor0(PwmOutPins::MOTOR4_PWM , DigitalOutPins::MOTOR4_DIR, 0);
DriveMotor motor1(PwmOutPins::MOTOR2_PWM, DigitalOutPins::MOTOR2_DIR, 0);
DriveMotor motor2(PwmOutPins::MOTOR1_PWM, DigitalOutPins::MOTOR1_DIR, 0);
DriveMotor motor3(PwmOutPins::MOTOR3_PWM, DigitalOutPins::MOTOR3_DIR, 0);

DriveMotor act1(PwmOutPins::MOTOR5_PWM, DigitalOutPins::MOTOR5_DIR, 0);
DriveMotor act2(PwmOutPins::MOTOR6_PWM, DigitalOutPins::MOTOR6_DIR, 0);


// シリアル通信を行うためのBufferedSerialオブジェクトを作成
BufferedSerial pc(USBTX, USBRX, 230400);  // TXピン、RXピン、ボーレート9600bpsを指定

//各関数にwait入れたほうがいいかも
float s=-1;//0以上1以下
float act1_s=-1;
float act2_s=1;

float act_t=0.02;
void stop()
{
    motor0.setPWM(0);
    motor1.setPWM(0);
    motor2.setPWM(0);
    motor3.setPWM(0);
}

void up()
{
  motor0.setPWM(-s);
  motor1.setPWM(s);
  motor2.setPWM(s);
  motor3.setPWM(-s);  
  wait_us(act_t*1000000);
}

void down()
{
  motor0.setPWM(s);
  motor1.setPWM(-s);
  motor2.setPWM(-s);
  motor3.setPWM(s); 
  wait_us(act_t*1000000);
}

void right()
{
  motor0.setPWM(s);
  motor1.setPWM(s);
  motor2.setPWM(-s);
  motor3.setPWM(-s);  
  wait_us(act_t*1000000);
}

void left()
{
  motor0.setPWM(-s);
  motor1.setPWM(-s);
  motor2.setPWM(s);
  motor3.setPWM(s);  
  wait_us(act_t*1000000);
}

void rightsenkai()
{
  motor0.setPWM(s);
  motor1.setPWM(s);
  motor2.setPWM(s);
  motor3.setPWM(s);  
  wait_us(act_t*1000000);
}

void leftsenkai()
{
  motor0.setPWM(-s);
  motor1.setPWM(-s);
  motor2.setPWM(-s);
  motor3.setPWM(-s);  
  wait_us(act_t*1000000);
}
void act1_sime()
{
  act1.setPWM(-act1_s);
  wait_us(act_t*1000000);
  act1.setPWM(0);
}

void act1_ake()
{
  act1.setPWM(act1_s);
   wait_us(act_t*1000000);
  act1.setPWM(0);
}
void act2_age()
{
  act2.setPWM(act2_s);
   wait_us(act_t*40000000);
  act2.setPWM(0);
}
/*
void act2_sage()
{
  act2.setPWM(-act2_s);
   wait_us(act_t*35000000);
  act2.setPWM(0);
}
*/

DigitalOut led1(LED1);//デバッグ用
int main() {
    char receivedChar;
    
    while (1) {
     motor3.setPWM(1);
        if (pc.readable()) {  // シリアルデータが受信可能か確認
            pc.read(&receivedChar, 1);  // 1バイトのデータを受信
            if (receivedChar == '0') 
            {
            stop();
            }
            if (receivedChar == '1') 
            {
              led1=1;
            right();

            }
            if (receivedChar == '2') left();
            if (receivedChar == '3') up();
            if (receivedChar == '4') down();
            if (receivedChar == '5') rightsenkai();
            if (receivedChar == '6') leftsenkai();
            if (receivedChar == '7') act2_age();
            //if (receivedChar == '8') act2_sage();
            if (receivedChar == '9') act1_ake();
            if (receivedChar == 'T') act1_sime();
                       
        }
    }
}

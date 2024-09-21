#include <mbed.h>
#include <math.h>
#include "driveMotor.hpp"
#include "parameters.hpp"

//#include <iostream>
//using namespace std;

//初期化
DriveMotor::DriveMotor(PinName pwm_pin, PinName dir_pin,bool sign): pwmOut(pwm_pin), dirOut(dir_pin),sign(sign)
{
    pwmOut.period_ms(PWM_PERIOD);
}

//PWMの書き込みここでモーターを動かしている
void DriveMotor::setPWM(float signed_pwm){
    if(signed_pwm>1)signed_pwm=1;
    if(signed_pwm<-1)signed_pwm=-1; 
    if(signed_pwm > 0){
        pwmOut.write(signed_pwm);
        dirOut.write(!sign);
    }else{
        pwmOut.write(-signed_pwm);
        dirOut.write(sign);
    }
}



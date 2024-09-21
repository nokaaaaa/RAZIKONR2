#pragma once
#include <mbed.h>
using namespace std;

class DriveMotor{
    public:
        //Encoder encoder;
        PwmOut pwmOut; //モーター
        DigitalOut dirOut;
    
        void setPWM(float signed_pwm); //PWMの直接書き込み


        DriveMotor(PinName pwm_pin, PinName dir_pin,bool sign);


        float pwm = 0.0f;
        bool sign;

};

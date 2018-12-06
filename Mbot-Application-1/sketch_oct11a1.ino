#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <MeMCore.h>

MeDCMotor motor_9(M1);
MeDCMotor motor_10(M2);

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
void Read_CNY70();
double temp1;
double CNY70;
double SPD;
double Offset_R_motor;
double Offset_L_motor;
MeLEDMatrix ledMtx_2(2);

void Read_CNY70()
{
    temp1 = digitalRead(15);
    temp1 += (2) * (digitalRead(14));
    temp1 += (4) * (digitalRead(17));
    temp1 += (8) * (digitalRead(16));
    temp1 += (16) * (digitalRead(18));
    CNY70 = temp1;
}

void setup(){  
    pinMode(15,INPUT);
    pinMode(14,INPUT);
    pinMode(17,INPUT);
    pinMode(16,INPUT);
    pinMode(18,INPUT);
}

void loop(){
    Read_CNY70();
    if(((CNY70)==(4))){
        motor_9.run(-220);
        motor_10.run(220);
    }else{
        if((((CNY70)==(2))) || (((CNY70)==(6))) || (((CNY70)==(1))) || (((CNY70)==(7)))){
            motor_9.run(-210);
            motor_10.run(10);
        }else{
            if((((CNY70)==(8))) || (((CNY70)==(12))) || (((CNY70)==(16))) || (((CNY70)==(28)))){
                motor_9.run(-10);
                motor_10.run(160);
            }else{
                if(((CNY70)==(31))){
                    motor_9.run(-220);
                    motor_10.run(220);
                }
            }
        }
    }
}


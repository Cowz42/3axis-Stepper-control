#include<iostream>
#include"stepper.h"



void TO_DO(unsigned char, bool);




Stepper X = Stepper(2, 3, 4, 17, &TO_DO);
Stepper Y = Stepper(24, 25, 8, 7, &TO_DO);
Stepper Z = Stepper(22, 10, 9, 11, &TO_DO);

int control(float x, float y, float z, float s_x, float s_y, float s_z) {
    X.set_speed(s_x);
    Y.set_speed(s_y);
    Z.set_speed(s_z);
    X.set_pos(x);
    Y.set_pos(y);
    Z.set_pos(z);
    while(1) {
        if (!(X.run() || Y.run() || Z.run())) {
            break;
        }
    }
};
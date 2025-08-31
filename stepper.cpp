#include "stepper.h"
#include <time.h>



Stepper::Stepper(unsigned char pin_1, unsigned char pin_2, unsigned char pin_3, unsigned char pin_4, void(*PIN_FUNC)(unsigned char, bool)) {
    pins[0] = pin_1;
    pins[1] = pin_2;
    pins[2] = pin_3;
    pins[3] = pin_4;
    clock_gettime(CLOCK_REALTIME, &last);
    values = 0b00000101;
};

void Stepper::set_pos(double new_pos) {
    position_to = new_pos;
    steps = int((position_to - position_real) / max_speed * step_to_deg);
    steps = steps >= 0?steps:-steps;
};


int Stepper::run() {

    if (steps == 0) {
        return 0;
    }

    clock_gettime(CLOCK_REALTIME, now);
    if (now > last + (max_speed / 1000000000)) {
        last = now;
        if (first) {
            first = false;
            values = values ^ 0b00001100;
        } else {
            first = false;
            values = values ^ 0b00000011;
        }

        if (values && 0b00001000) {
            pin_func(pins[0], true);
        } else {
            pin_func(pins[0], false);
        }
        if (values && 0b00000100) {
            pin_func(pins[1], true);
        } else {
            pin_func(pins[1], false);
        }
        if (values && 0b00000010) {
            pin_func(pins[2], true);
        } else {
            pin_func(pins[2], false);
        }
        if (values && 0b00000001) {
            pin_func(pins[3], true);
        } else {
            pin_func(pins[3], false);
        }
    }
    steps--;
    return steps;
};

void Stepper::set_speed(float speed) {
    max_speed = speed;
};


#ifndef stepper_h
#define stepper_h

class Stepper {
private:
    unsigned char pins[4];
    double position_real;
    int position_step;
    void (*pin_func)(unsigned char, bool);
    int steps;
    float max_speed;
    double position_to;
    struct timespec now;
    struct timespec last;
    float step_to_deg;
    char values;
    bool first = true;

public:
    Stepper(unsigned char pin_1, unsigned char pin_2, unsigned char pin_3, unsigned char pin_4, void(*PIN_FUNC)(unsigned char, bool));

    int run();

    void set_pos(double new_pos);

    void set_speed(float speed);

};


#endif
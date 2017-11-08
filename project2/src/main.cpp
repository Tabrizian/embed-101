#include <mbed.h>

DigitalOut ledRed(PTC1);
DigitalOut ledGreen(PTC2);

DigitalOut test1(LED1);
DigitalOut test2(LED2);

InterruptIn switch1(PTD1);
InterruptIn switch2(PTD2);

int priority = 3;

void task1() {
    wait(0.25);
    ledRed = 1;
    wait(0.25);
    ledRed = 0;
}

void task2() {
    wait(0.25);
    ledGreen = 1;
    wait(0.25);
    ledGreen = 0;
    NVIC_SetPriority(PORTD_IRQn, 255);
}

void task3() {
    wait(0.25);
    ledGreen = 1;
    wait(0.25);
    ledGreen = 0;
    wait(0.25);
    ledRed = 1;
    wait(0.25);
    ledRed = 0;
}

void task4() {
    wait(0.25);
    ledGreen = 1;
    ledRed = 1;
    wait(0.25);
    ledGreen = 0;
    ledRed = 0;
}

void switch1ISR(){
    int value = switch1.read();
    // while (value == 1) {
    //     wait(0.010);
    //     value = switch1.read();
    // }
    if (priority == 1) {
        priority = 3;
    } else {
        priority = 1;
    }
}

void switch2ISR(){
    int value = switch2.read();
    // while (value == 0) {
    //     wait(0.010);
    //     value = switch2.read();
    // }
    if (priority == 2) {
        priority = 3;
    } else if (priority == 3){
        priority = 2;
    }
}

void schedule() {
    switch (priority) {
        case 1:
            task3();
            break;
        case 2:
            task4();
            break;
        case 3:
            task1();
            task2();
            break;
    }
}

int main()
{
    switch1.mode(PullUp);
    switch2.mode(PullUp);
    switch1.fall(&switch1ISR);
    switch2.fall(&switch2ISR);
    while (1)
    {
        schedule();
    }
}

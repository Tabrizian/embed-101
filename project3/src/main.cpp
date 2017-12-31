#include <mbed.h>

DigitalOut led1(PTE1);
DigitalOut led2(PTA17);
DigitalOut led3(PTD3);
DigitalOut led4(PTC4);
DigitalOut led5(PTC5);
DigitalOut led6(PTC6);

DigitalIn emergency(PTD1);

int main()
{
    emergency.mode(PullUp);
    emergency.fall(&emergency);
    while (1) {
    }
}
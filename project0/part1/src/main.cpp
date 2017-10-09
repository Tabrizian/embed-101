#include <mbed.h>

int main() {
    DigitalOut myled(LED2);
    DigitalIn myInput(PTE3);
    myInput.mode(PullUp);

    while(1) {
       myled = myInput;
    }
}

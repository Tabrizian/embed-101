#include <mbed.h>
bool mode = true;
float temp;
Serial pc(USBTX, USBRX);
DigitalIn myInput(PTE3);
PwmOut myled(LED2);

void increase()
{
    float value;
    value = myled;
    if (mode)
    {
        temp = myled + 0.2;
        if (temp == 1.0f)
        {
            mode = false;
        }
        myled = temp;
    }
    else
    {
        temp = myled - 0.2;
        if (fabsf(temp - 0.0) < 0.0001)
        {
            mode = true;
        }
        myled = temp;
    }
}

int main()
{
    
    myInput.mode(PullUp);
    pc.printf("Hello World!\n");
    // put your setup code here, to run once:
    myled.period(0.01f);
    myled = 0.0;
    while (1)
    {
        if (myInput == false) {
            while(myInput == false);
            pc.printf("Increased!\n");
            increase();
            wait_ms(100);
        }
    }
}
#include <mbed.h>
bool mode = true;
float temp = 0;
Serial pc(USBTX, USBRX);
DigitalIn myInput(PTE3);
DigitalOut myled(LED2);

void increase()
{
    float value;
    value = myled;
    if (mode)
    {
        temp = temp + 0.2;
        if (temp == 1.0f)
        {
            mode = false;
        }
      
    }
    else
    {
        temp = temp - 0.2;
        if (fabsf(temp - 0.0) < 0.0001)
        {
            mode = true;
        }
    }
}

int main()
{
    
    myInput.mode(PullUp);
    pc.printf("Hello World!\n");
    // put your setup code here, to run once:
    myled = 0;
    while (1)
    {
        if (myInput == false) {
            while(myInput == false);
            pc.printf("Increased!\n");
            increase();
        }

        myled = 0;
        wait_us(temp * 100);
        myled = 1;
        wait_us(100 - temp * 100);
    }
}
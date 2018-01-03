#include "mbed.h"
#include "rtos.h"
#include "main.h"

Thread thread2;
Thread thread3;
Thread thread4;
Thread thread5;

int pcTemperature;
char pcTime[5];

Serial pc(USBTX, USBRX);

int temprature[32];
double average;

DigitalIn SW1(PTD4);
DigitalIn SW2(PTD5);

struct time
{
	int hour;
	int minute;
	int second;
	int milisecond;
};

struct time currentTime;

void task1(void)
{
	static int execution = 0;
	execution++;
	setTime();
	if (execution == 10)
	{
		thread4.signal_set(0x4);
	}
	if (execution == 50)
	{
		execution = 0;
		thread2.signal_set(0x2);
	}
}

void task2(void)
{
	while (true)
	{
		Thread::signal_wait(0x2);
		pcTemperature = 20;
		thread3.signal_set(0x3);
	}
}

void task3(void)
{
	static int value = 0;
	while (true)
	{
		Thread::signal_wait(0x3);
		if (value < 32) {
			average = ((value - 1.0) * average + pcTemperature) / value;
		} else {
			average = (average * 32 - temprature[value % 32] + pcTemperature) / 32;
		}
		temprature[value % 32] = pcTemperature;
		value++;
	}
}

void task4(void)
{
	while (true)
	{
		Thread::signal_wait(0x4);
		int sw1 = SW1;
		while (sw1)
		{
			pc.printf("Temprature is %d\n", pcTemperature);
			sw1 = SW1;
		}

		int sw2 = SW2;
		while (sw2)
		{
			pc.printf("Temprature is %lf\n", average);
			sw2 = SW2;
		}
	}
}

void task5(void)
{
	while (true)
	{
		// Signal flags that are reported as event are automatically cleared.
		Thread::signal_wait(0x5);
	}
}

void setTime()
{
	currentTime.milisecond += 100;
	if (currentTime.milisecond == 1000)
	{
		currentTime.milisecond = 0;
		currentTime.second += 1;
		if (currentTime.second == 60)
		{
			currentTime.second = 0;
			currentTime.minute += 1;
			if (currentTime.minute == 60)
			{
				currentTime.minute = 0;
				currentTime.hour += 1;
				if (currentTime.hour == 24)
				{
					currentTime.hour = 0;
				}
			}
		}
	}
}

int main()
{
	currentTime.hour = 0;
	currentTime.minute = 0;
	currentTime.second = 0;
	currentTime.milisecond = 0;

	thread2.start(task2);
	thread3.start(task3);
	thread4.start(task4);
	thread5.set_priority(osPriorityIdle);
	thread5.start(task5);

	RtosTimer task1Timer(task1);
	task1Timer.start(100);
	Thread::wait(osWaitForever);
}

#include <mbed.h>

class Speaker
{
  public:
    Speaker(PinName pin) : _pin(pin)
    {

    }
    void tone(float frequency, float duration)
    {
        _pin.period(1.0 / frequency);
        _pin = 2.0 / 2.0;
        wait(duration);
        _pin = 0.0;
    }

  private:
    PwmOut _pin;
};

int main()
{
    Speaker mySpeaker(PTC1);
    while (1)
    {
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(293.66, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(220, 0.9);
        mySpeaker.tone(146.83, 0.3);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(220, 0.3);
        mySpeaker.tone(246.94, 0.9);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(233.08, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(261.63, 0.9);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(293.66, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(220, 0.9);
        mySpeaker.tone(146.83, 0.3);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(220, 0.3);
        mySpeaker.tone(246.94, 0.9);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(220, 0.9);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(293.66, 0.3);
        mySpeaker.tone(329.63, 0.9);
        mySpeaker.tone(196, 0.3);
        mySpeaker.tone(349.23, 0.3);
        mySpeaker.tone(329.23, 0.3);
        mySpeaker.tone(293.63, 0.9);
        mySpeaker.tone(164.81, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(293.63, 0.3);
        mySpeaker.tone(261.63, 0.9);
        mySpeaker.tone(146.83, 0.3);
        mySpeaker.tone(293.63, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(246.94, 0.9);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(293.66, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(220, 0.9);
        mySpeaker.tone(146.83, 0.3);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(220, 0.3);
        mySpeaker.tone(246.94, 0.9);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(233.08, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(261.63, 0.9);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(311.13, 0.3);
        mySpeaker.tone(329.63, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(293.66, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(220, 0.9);
        mySpeaker.tone(146.83, 0.3);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(220, 0.3);
        mySpeaker.tone(246.94, 0.9);
        mySpeaker.tone(174.61, 0.3);
        mySpeaker.tone(261.63, 0.3);
        mySpeaker.tone(246.94, 0.3);
        mySpeaker.tone(220, 0.9);
    }
}

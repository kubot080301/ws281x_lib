#include "Arduino.h"
#include "Stick.h"

void  setup()
{
    //定義腳位初始化
    //燈條1 Stick1
    //燈條2 Stick2 ...
    Stick1.begin();
    Stick2.begin();
    Stick3.begin();
    Stick4.begin();

    //燈條1初始化為普通燈
    //燈條2初始化為呼吸燈
    Stick1.Init_None(Stick1.Color(255, 0, 0));
    Stick2.Init_Fade(Stick2.Color(0, 255, 0), Stick2.Color(0, 0, 0), 2000, 10, FORWARD);
    Stick3.Init_RainbowCycle(20);
    Stick4.TheaterChase(Stick4.Color(100, 255, 0), 10, FORWARD);

}

void loop()
{
    //燈條1不斷變化
    Stick1.Update();
    //燈條2不斷變化...
    Stick2.Update();
    Stick3.Update();
    Stick4.Update();

}


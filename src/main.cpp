#include "Arduino.h"
#include "Stick.h"

void  setup()
{
    //定義腳位初始化
    //燈條1 Stick1
    //燈條2 Stick2
    Stick1.begin();
    Stick2.begin();

    //燈條1初始化為掃描燈
    //燈條2初始化為呼吸燈
    Stick1.Init_None(Stick1.Color(255, 0, 0));
    Stick2.Init_Fade(Stick2.Color(0, 255, 0), Stick2.Color(0, 0, 0), 2000, 10, FORWARD);
}

void loop()
{
    //燈條1不斷變化
    Stick1.Update();
    //燈條2不斷變化
    Stick2.Update();
}


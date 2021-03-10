#include "Arduino.h"
#include "Neo_Patterns.h"

void Ring1_Complete();
void Ring2_Complete();
void Stick1_Complete();
void Stick2_Complete();

Neo_Patterns Ring1(24, 5, NEO_GRB + NEO_KHZ800, &Ring1_Complete);
Neo_Patterns Ring2(16, 6, NEO_GRB + NEO_KHZ800, &Ring2_Complete);
Neo_Patterns Stick1(16, 7, NEO_GRB + NEO_KHZ800, &Stick1_Complete);
Neo_Patterns Stick2(13, 8, NEO_GRB + NEO_KHZ800, &Stick2_Complete);

void  setup()
{
    Serial.begin(115200);

    //定義腳位初始化 父項函數
    Ring1.begin();
    Ring2.begin(); 
    Stick1.begin();
    Stick2.begin();

    Ring1.Init_RainbowCycle(50, FORWARD);
    Ring2.Init_TheaterChase(Ring2.Color(255,255,0), Ring2.Color(0,0,50), 100, FORWARD);
    Stick1.Init_Scanner(Stick1.Color(255, 0, 0), 10);
    Stick2.Init_Fade(Stick2.Color(100, 255, 0), Stick2.Color(255, 100, 0), 1000, 500, FORWARD);
}

void loop()
{
    Ring1.Update();
    Ring2.Update();
    Stick1.Update();
    Stick2.Update();
}

void Ring1_Complete()
{
    Ring1.Reverse();
}

void Ring2_Complete()
{
    Ring2.Reverse();
}

void Stick1_Complete()
{
    Stick1.Reverse();
}

void Stick2_Complete()
{
    Stick2.Reverse();
}
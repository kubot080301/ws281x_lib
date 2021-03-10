#include "Neo_Patterns.h"

#include <Arduino.h>

void (*OnComplete)();       //狀態完成時回饋

//構造回調函式
Neo_Patterns::Neo_Patterns(uint16_t pixels, uint8_t pin, uint8_t type, void (*callback)())
    :Adafruit_NeoPixel(pixels, pin, type)
{
    OnComplete = callback;
}


//檢查自上次更新以來所經過的時間，如果還沒做任何事情，則立即返回。
void Neo_Patterns::Update()
{
    if((millis() - lastUpdate) > Interval) // 更新時間到時更新
    {
        lastUpdate = millis();
        switch(ActivePattern)
        {
            case RAINBOW_CYCLE:
                RainbowCycle();
                break;
            case THEATER_CHASE:
                TheaterChase();
                break;
            case COLOR_WIPE:
                ColorWipe();
                break;
            case SCANNER:
                Scanner();
                break;
            case FADE:
                Fade();
                break;
            default:
                break;
        }
    }
}

//當前步驟執行完畢後回傳並更新 順時針與逆時針
void Neo_Patterns::Increment()
{
    if (Direction == FORWARD)
    {
        Index++;
        if (Index >= TotalSteps)
        {
            Index = 0;
            if (OnComplete != NULL)
            {
                OnComplete(); // 調用完成後回調
            }
        }
    }
    else // Direction == REVERSE
    {
        --Index;
        if (Index <= 0)
        {
        Index = TotalSteps-1;
            if (OnComplete != NULL)
            {            
                OnComplete(); // 調用完成後回調
            }
        }
    }    
}

//若傳送方向為逆時針
void Neo_Patterns::Reverse()
{
    if (Direction == FORWARD)
    {
        Direction = REVERSE;
        Index = TotalSteps-1;
    }
    else
    {
        Direction = FORWARD;
        Index = 0;
    }    
}

//初始化全亮
void Neo_Patterns::Init_None(uint32_t color)
{
    ActivePattern = NONE;
    TotalSteps = numPixels();
    Color1 = color;
    Index = 0;
}

//整條同一顏色
void Neo_Patterns::None()
{
    for (int i = 0;i < numPixels(); i++)
    {
        setPixelColor(i, Color1);
    }
    show();
}

//初始化彩虹循環燈
void Neo_Patterns::Init_RainbowCycle(uint8_t interval, direction dir = FORWARD)
{
    ActivePattern = RAINBOW_CYCLE;
    Interval = interval;
    TotalSteps = 255;
    Index = 0;
    Direction = dir;
}

//彩虹循環燈函式
void Neo_Patterns::RainbowCycle()
{
    for(int i=0; i< numPixels(); i++)
    {
        setPixelColor(i, Wheel(((i * 256 / numPixels()) + Index) & 255));
    }
    show();
    Increment();
}

//初始化跑馬燈
void Neo_Patterns::Init_TheaterChase(uint32_t color1, uint32_t color2, uint8_t interval, direction dir = FORWARD)
{
    ActivePattern = THEATER_CHASE;
    Interval = interval;
    TotalSteps = numPixels();
    Color1 = color1;
    Color2 = color2;
    Index = 0;
    Direction = dir;
}

//跑馬燈函式
void Neo_Patterns::TheaterChase()
{
    for(int i=0; i< numPixels(); i++)
    {
        if ((i + Index) % 3 == 0)
        {
        setPixelColor(i, Color1);
        }
        else
        {
        setPixelColor(i, Color2);
        }
    }
    show();
    Increment();    
}

//初始化漸變燈
void Neo_Patterns::Init_ColorWipe(uint32_t color, uint8_t interval, direction dir = FORWARD)
{
    ActivePattern = COLOR_WIPE;
    Interval = interval;
    TotalSteps = numPixels();
    Color1 = color;
    Index = 0;
    Direction = dir;
}

//漸變燈函式
void Neo_Patterns::ColorWipe()
{
    setPixelColor(Index, Color1);
    show();
    Increment();

}

//初始化掃描燈
void Neo_Patterns::Init_Scanner(uint32_t color1, uint8_t interval)
{
    ActivePattern = SCANNER;
    Interval = interval;
    TotalSteps = (numPixels() - 1) * 2;
    Color1 = color1;
    Index = 0;    
}

//掃描燈函式
void Neo_Patterns::Scanner()
{
    for (int i = 0; i < numPixels(); i++)
    {
        if (i == Index) 
        {
            setPixelColor(i, Color1);
        }
        else if (i == TotalSteps - Index) 
        {
            setPixelColor(i, Color1);
        }
        else 
         {
            setPixelColor(i, DimColor(getPixelColor(i)));
        }
    }
    show();
    Increment();    
}

//初始化呼吸燈
void Neo_Patterns::Init_Fade(uint32_t color1, uint32_t color2, uint16_t steps, uint8_t interval, direction dir = FORWARD)
{
    ActivePattern = FADE;
    Interval = interval;
    TotalSteps = steps;
    Color1 = color1;
    Color2 = color2;
    Index = 0;
    Direction = dir;
}

//呼吸燈函式
void Neo_Patterns::Fade()
{
    uint8_t red = ((Red(Color1) * (TotalSteps - Index)) + (Red(Color2) * Index)) / TotalSteps;
    uint8_t green = ((Green(Color1) * (TotalSteps - Index)) + (Green(Color2) * Index)) / TotalSteps;
    uint8_t blue = ((Blue(Color1) * (TotalSteps - Index)) + (Blue(Color2) * Index)) / TotalSteps;    
    Fade_set(Color(red, green, blue));
    show();
    Increment();
}

//呼吸燈設定
void Neo_Patterns::Fade_set(uint32_t color)
{
    for (int i = 0; i < numPixels(); i++)
    {
        setPixelColor(i, color);
    }
    show();
}

uint32_t Neo_Patterns::DimColor(uint32_t color)
{
    uint32_t dimColor = Color(Red(color) >> 1, Green(color) >> 1, Blue(color) >> 1);
    return dimColor;
}

uint8_t Neo_Patterns::Red(uint32_t color)
{
    return (color >> 16) & 0xFF;
}

uint8_t Neo_Patterns::Green(uint32_t color)
{
    return (color >> 8) & 0xFF;
}

uint8_t Neo_Patterns::Blue(uint32_t color)
{
    return color & 0xFF;
}

uint32_t Neo_Patterns::Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85)
    {
        return Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    else if(WheelPos < 170)
    {
        WheelPos -= 85;
        return Color(0, WheelPos * 3, 255 - WheelPos * 3);
        }
    else
    {
        WheelPos -= 170;
        return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
    }
}

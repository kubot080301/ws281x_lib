#ifndef KUBOT_NEO_PATTERNS_H_
#define KUBOT_NEO_PATTERNS_H_

#include "Adafruit_NeoPixel.h"

// 列舉變化模式(狀態)  全亮、彩虹循環燈、跑馬燈、漸變燈、掃描燈、呼吸燈
enum  pattern {NONE, RAINBOW_CYCLE, THEATER_CHASE, COLOR_WIPE, SCANNER, FADE};
// 列舉發送方向(行為)  順時針、逆時針
enum  direction {FORWARD, REVERSE};

class Neo_Patterns : public Adafruit_NeoPixel
{
    public:
        /*
        狀態機變量
        WS281X燈條控制，需要定應DMA發送長度、燈條顏色、變化時間
        可能的狀態、狀態變化條件(時間)、狀態觸發機制
        */
        pattern ActivePattern;      //正在運行的模式
        direction Direction;        //發送方向

        unsigned long Interval;     //時間差
        unsigned long lastUpdate;   //上次更新時間

        uint32_t Color1;            //正在進行的顏色
        uint32_t Color2;            //一燈條組數定義

        uint16_t TotalSteps;        //總步驟
        uint16_t Index;             //當前的步驟


        Neo_Patterns(uint16_t, uint8_t, uint8_t, void(*)());
                Neo_Patterns(void);
            ~Neo_Patterns(){};

    public:
        /*
        狀態函數組
        */
        void Update();              //更新狀態
        void Increment();           //當前步驟後更新
        void Reverse();             //恢復

    public:    
        /*
        變化方式函數組
        */
        //整條同一顏色(顏色)
        void Init_None(uint32_t);
        void None();
        //彩虹循環(間格, 發送方向)
        void Init_RainbowCycle(uint8_t, direction);     
        void RainbowCycle();
        //跑馬燈(顏色1, 顏色2, 間格, 發送方向)
        void Init_TheaterChase(uint32_t , uint32_t , uint8_t , direction);
        void TheaterChase();
        //漸變燈(顏色, 間格, 發送方向)
        void Init_ColorWipe(uint32_t, uint8_t, direction);
        void ColorWipe();
        //掃描燈(顏色, 間格)
        void Init_Scanner(uint32_t , uint8_t );
        void Scanner();
        //呼吸燈(顏色1, 顏色2, 呼吸時間, 間格, 發送方向)
        void Init_Fade(uint32_t, uint32_t, uint16_t, uint8_t, direction);
        void Fade();
        void Fade_set(uint32_t);

    public:
        uint32_t DimColor(uint32_t);
        uint8_t Red(uint32_t);
        uint8_t Green(uint32_t);
        uint8_t Blue(uint32_t);
        uint32_t Wheel(byte);
    
};

#endif
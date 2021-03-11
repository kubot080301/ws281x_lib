# WS281X_library
基於Arduino開發的ws281x系列燈條控制，引用 Adafruit_NeoPixel 庫並去除delay改用狀態機對時鐘做監控，實現多通道不同狀態並自由控制模式。
## Branches
### 1.ws2812_test1

流水帳寫法 : 參考自  Bill Earl 的 Multi-tasking the Arduino Part.3。

### 2.ws2812_test3

Library型式，在主程式宣告要使用的燈條，並做狀態控制。

### 3.ws2812_test4

Library型式，引用宣告好的燈條，直接調用解函式。

### 4.ws2812_test5

Library型式，參考 WS2812FX 庫，刪除回掉，共62種變化函式。

### 5.ws2812_test6
基於STM32F103C8Tx Jlink SW 燒入Arduino框架 並實驗test5的燈調控制。
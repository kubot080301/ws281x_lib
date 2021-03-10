# WS281X_libray
基於Arduino開發的ws281x系列燈條控制，引用 Adafruit_NeoPixel 庫並去除delay改用狀態機對時鐘做監控，實現多通道不同狀態並自由控制模式。
## branches
### 1.ws2812_test1

流水帳寫法 : 參考自  Bill Earl 的 Multi-tasking the Arduino Part.3。

### 2.ws2812_test3

Libray型式，在主程式宣告要使用的燈條，並做狀態控制。

### 3.ws2812_test4

Libray型式，引用宣告好的燈條，直接調用解函式。


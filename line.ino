#include <RGBmatrixPanel.h>                                             // Подключаем библиотеку для работы с матрицей
#include <Adafruit_GFX.h>
// Используем эти выводы, если матрица подключена к Arduino MEGA
#define CLK 11
#define OE   9
#define LAT 10

#define A   A0                                                          // Вывод Arduino, к которому подключён вывод A матрицы
#define B   A1                                                          // Вывод Arduino, к которому подключён вывод B матрицы
#define C   A2                                                          // Вывод Arduino, к которому подключён вывод C матрицы
#define D   A3                                                          // Вывод Arduino, к которому подключён вывод D матрицы

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);              // Объявляем объект matrix для работы с матрицей 64х32,включаем двойную буферизацию
int8_t ball[3][2] = {{ 13, 15 },{ 30, 15 },{ 48, 15}};
static const uint16_t color[3] = {matrix.Color333(0, 0, 3),matrix.Color333(0, 3, 0), matrix.Color333(3, 0, 0)};
void setup() {
  matrix.fillScreen(0);                                                 // очищаем экран
  matrix.begin();   
}

void loop() {  
int x [2] = {25, 9}; 
int z[2] = {25, 45};   
int r = random(0,2);
matrix.fillRect(9, 11, 10, 10, color[random(0,3)]);
delay(random(150,700));
matrix.fillCircle(ball[1][0], ball[1][1], 6, color[random(0,3)]);
delay(random(150,700));
matrix.fillTriangle(55, 23, 41, 15, 48, 9, color[random(0,3)]);
delay(random(150,700));
matrix.swapBuffers(false);
}
                                                  
//int potValue =        
//  switch (potValue){
//  case default:
//   case 1:
    /* case 2:
     matrix.fillScreen(0);
     case 3:
// matrix.swapBuffers(false);                               
}*/

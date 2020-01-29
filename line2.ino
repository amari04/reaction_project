#include <RGBmatrixPanel.h>                                             // Подключаем библиотеку для работы с матрицей
#define CLK 11
#define OE   9
#define LAT 10
#define A   A0                                                          // Вывод Arduino, к которому подключён вывод A матрицы
#define B   A1                                                          // Вывод Arduino, к которому подключён вывод B матрицы
#define C   A2                                                          // Вывод Arduino, к которому подключён вывод C матрицы
#define D   A3                                                          // Вывод Arduino, к которому подключён вывод D матрицы
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);             // Объявляем объект matrix для работы с матрицей 64х32
uint8_t r, g, b;                                                        // Переменные цвета светодиодов
void setup() {
  matrix.begin();                                                       // Инициируем работу с матрицей
}
void loop() {
  matrix.fillScreen(0);                                                 // очищаем экран при каждом выполнении цикла
  r = 0;g = 0;b = 7;  
  int y = 0;
  int x = 0;
  matrix.drawPixel(30, 15, matrix.Color333(7, 0, 7));


   for (y = 15; y>2; y--){
  matrix.drawPixel(30, y, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
   delay(40);             
  }
  for (y = 15; y<28; y++){
  matrix.drawPixel(30, y, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
  delay(20);
}
 for (x = 30; x>17; x--){
  matrix.drawPixel(x, 15, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
  delay(20);
}
for (x = 30; x<43; x++){
  matrix.drawPixel(x, 15, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
  delay(20);
}
   y = 15;
   x = 30;
  while ((x>2) and (y<25)) {
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    delay(30);
   x++;
   y++;
 }
   y = 15;
   x = 30;
  while ((x>2) and (y<25)) {
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    delay(30);
   x--;
   y++;
 }
   y = 15;
   x = 30;
  while ((x>2) and (y>5)) {
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    delay(30);
   x--;
   y--;
 }
   y = 15;
   x = 30;
  while ((x < 43) and (y > 5)) {
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    delay(30);
   x++;
   y--;
 }
}

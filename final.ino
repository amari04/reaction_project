#include <RGBmatrixPanel.h>                                             // Подключаем библиотеку для работы с матрицей
#include <Adafruit_GFX.h>
#include <LiquidCrystal.h>
#define CLK 11
#define OE   9
#define LAT 10
#define A   A0                                                          // Вывод Arduino, к которому подключён вывод A матрицы
#define B   A1                                                          // Вывод Arduino, к которому подключён вывод B матрицы
#define C   A2                                                          // Вывод Arduino, к которому подключён вывод C матрицы
#define D   A3                                                          // Вывод Arduino, к которому подключён вывод D матрицы
uint8_t r, g, b;  
RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, true, 64);              // Объявляем объект matrix для работы с матрицей 64х32, включаем двойную буферизацию
double number;
long sTime; 
float avg1 = 0;
int i = 0;
int8_t ball[3][2] = {{ 13, 15 },{ 30, 15 },{ 48, 15}};
static const uint16_t color[4] = {matrix.Color333(0, 0, 3),matrix.Color333(0, 3, 0), matrix.Color333(3, 0, 0), matrix.Color333(0, 0, 7)};
boolean butt1;
boolean butt2;
int butt3;
int soundPin = 12;
const char restxt[] = "Results!";
const char wait[] = "Wait!";
const char choose[] = "Choose the interface mode: 1.OZO 2.P DO 3.Sound ";
int16_t textX = matrix.width();
int16_t textMin = sizeof(choose) * -6;
const char p1[] = "1  2  3";
int potValue;
int pushcount;
int findcount, badfindcount;
int f[2] = {25, 9}; 
int z[2] = {25, 45};   
int n;
int button_old = 1;
int count = 0;
int find_color = 2;
int find_object = 0;
int buttonPin = 5;
int ch_t = 0;
int ch_f = 0;
int ch_w = 0;
static const uint16_t Color_C[6] = {                                  // Массив с цветами кругов
  matrix.Color333(3, 5, 3),                                             // Синий
  matrix.Color333(0, 7, 0),                                             // Зелёный
  matrix.Color333(3, 4, 0), 
  matrix.Color333(3, 0, 6), 
  matrix.Color333(3, 1, 6), 
  matrix.Color333(3, 3, 3)
};
void setup() {
  Serial.begin(9600);
  pinMode(5, OUTPUT);      
  pinMode(6, OUTPUT);     
  pinMode(7, OUTPUT);         
  pinMode(soundPin, OUTPUT);                                       
  matrix.begin();   
  matrix.setTextWrap(false);   
}
void loop() {
  r = 0;g = 0;b = 7;  
  int y = 0;
  int x = 0; 
if (digitalRead(7) == HIGH) {
  potValue = 3;
  delay(5);
}
  if (digitalRead(6) == HIGH) {
  potValue = 2;
  delay(5);
}
if (digitalRead(5) == HIGH) {
  potValue = 1;
  delay(5);
}
  switch (potValue){
  case 1:
  matrix.fillScreen(0);
  matrix.setCursor(17, 5);
  matrix.print("OZO");
  matrix.swapBuffers(false);
  delay(2000);
   matrix.fillScreen(0);    
   matrix.setCursor(30, 13);
   matrix.print("Find!");
   if(find_object == 0) {   
   matrix.fillRect(9, 11, 10, 10, Color_C[find_color]);
   matrix.swapBuffers(false);
   matrix.fillScreen(0);  
   delay(2000);
   }
   else
   {
   matrix.fillScreen(0);  
   matrix.fillCircle(16, 8, 6, Color_C[find_color]);
   matrix.swapBuffers(false);
   delay(2000);
   matrix.fillScreen(0); 
   }
   for (int i = 0; i < 5; i++) { 
    matrix.fillScreen(0);  
    int color_f_c = random(4);
    int color_f_r = random(4);
    matrix.fillRect(9, 11, 10, 10, Color_C[color_f_r]);
    matrix.fillCircle(30, 15, 6, Color_C[color_f_c]);
    matrix.swapBuffers(false);
    if(find_object >= 0){
      if(color_f_r == find_color){
        if (digitalRead(buttonPin) == HIGH) {
          delay(20);
        find_object++;}
        else{ ch_f++;}
       }
     }  
    delay(2000);
   }
  matrix.fillScreen(0);
  matrix.setCursor(5, 7);
  matrix.print("Ok click ");
  matrix.setCursor(24, 20);
  matrix.print(ch_f);
  matrix.swapBuffers(false);
  delay(3000);
  matrix.fillScreen(0);
  delay(3000);
  matrix.fillScreen(0);

  potValue = 0;
  break;

  case 2:
  matrix.fillScreen(0);
  matrix.setCursor(17, 5);
  matrix.print("R DO");
  matrix.swapBuffers(false);
  delay(2000);
  matrix.fillScreen(0);  
  matrix.drawPixel(30, 15, matrix.Color333(7, 0, 7));
  int x,y;
  for (y = 15; y>2; y--){
   matrix.fillScreen(0);
   matrix.drawPixel(30, y, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
   matrix.swapBuffers(false);
   if (digitalRead(6) == HIGH){
   pushcount+=1;
   delay(500);
   }  
   delay(40);   
  }    
  for (y = 15; y<28; y++){
    matrix.fillScreen(0);
    matrix.drawPixel(30, y, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
    matrix.swapBuffers(false);
    if (digitalRead(6) == HIGH){
    pushcount+=1;
    delay(500);
    }  
    delay(20);
}
 for (x = 30; x>17; x--){
  matrix.fillScreen(0);
  matrix.drawPixel(x, 15, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
  matrix.swapBuffers(false);
  if (digitalRead(6) == HIGH){
    pushcount+=1;
    delay(500);
    }  
  delay(20);
}
for (x = 30; x<43; x++){
  matrix.fillScreen(0);
  matrix.drawPixel(x, 15, matrix.Color333(r, g, b));   // случайным образом зажигаем светодиоды, включая их случайным цветом
    matrix.swapBuffers(false);
if (digitalRead(6) == HIGH){
    pushcount+=1;
    delay(500);
    }  
  delay(20);
}
   y = 15;
   x = 30;
  while ((x>2) and (y<25)) {
    matrix.fillScreen(0);
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    matrix.swapBuffers(false);
if (digitalRead(6) == HIGH){
    pushcount+=1;
    delay(500);
    } 
    delay(30);
   x++;
   y++;
 }
   y = 15;
   x = 30;
  while ((x>2) and (y<25)) {
    matrix.fillScreen(0);
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    matrix.swapBuffers(false);
    if (digitalRead(6) == HIGH){
    pushcount+=1;
    delay(500);
    } 
    delay(30);
   x--;
   y++;
 }
   y = 15;
   x = 30;
  while ((x>2) and (y>5)) {
    matrix.fillScreen(0);
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    matrix.swapBuffers(false);
if (digitalRead(6) == HIGH){
    pushcount+=1;
    delay(500);
    } 
    delay(30);
   x--;
   y--;
 }
   y = 15;
   x = 30;
  while ((x<43) and (y>5)) {
    matrix.fillScreen(0);
    matrix.drawPixel(x, y, matrix.Color333(r, g, b));
    matrix.swapBuffers(false);
 if (digitalRead(6) == HIGH){
    pushcount+=1;
    delay(500);
    } 
    delay(30);
   x++;
   y--;
 }
  if (pushcount==8){
  matrix.fillScreen(0);
  matrix.setCursor(5, 7);
  matrix.print("Ok click ");
  matrix.setCursor(24, 20);
  matrix.print(pushcount);
  matrix.swapBuffers(false);
  }
  if (pushcount<8){
  matrix.fillScreen(0);
  matrix.setCursor(7, 7);
  matrix.print("Missed ");
  matrix.setCursor(24, 20);
  matrix.setTextColor(matrix.Color333(3,0,0));
  matrix.print(8-pushcount);
  matrix.swapBuffers(false);
  }
  if (pushcount>8){
  matrix.fillScreen(0);
  matrix.setCursor(7, 7);
  matrix.print("False click ");
  matrix.setCursor(24, 20);
  matrix.setTextColor(matrix.Color333(3,0,0));
  matrix.print(pushcount-8);
  matrix.swapBuffers(false);
  }
   delay(5000);

  potValue = 0;
  break;
  
  case 3:
  matrix.fillScreen(0);
  matrix.setCursor(2, 7);
  matrix.print("Sound test ");
  matrix.swapBuffers(false);
  delay(2000);
matrix.fillScreen(0);
matrix.setCursor(17, 5); 
matrix.print(wait);
butt3 = digitalRead(7);
butt2 = digitalRead(6);
butt1 = digitalRead(5);
matrix.swapBuffers(false);
number = random(500, 5000);
  for (i = 0; i<5; i=i+1){
  delay(number); 
  matrix.fillScreen(0);
  matrix.setCursor(17, 5);
  matrix.print("Press!");  
  matrix.swapBuffers(false);
  tone(soundPin, 500);
  sTime = millis(); 
  while (digitalRead(7) == LOW);
  noTone(soundPin);
  matrix.fillScreen(0);
  matrix.setCursor(17, 5);
  matrix.print("Time: ");
  matrix.setCursor(17, 15);
  matrix.print((millis() - sTime) / 1000.0);
  avg1=avg1 + ((millis() - sTime) / 1000.0);
  delay(2000);
  matrix.swapBuffers(false);
  matrix.fillScreen(0);
  noTone(soundPin);
  delay (3000);
  }
  matrix.fillScreen(0);
  matrix.setCursor(5, 7);
  matrix.print("Your time:");
  matrix.setCursor(17, 15);
  matrix.print(avg1/5, 3);
   matrix.swapBuffers(false); 
  delay (5000);
  delay(2000);
  potValue = 0;
  break;
  default:
  matrix.fillScreen(0);   
  matrix.setTextColor(matrix.Color333(0,0,7));                // Устанавливаем цвет текста
  avg1 = 0; pushcount = 0;   
  matrix.setCursor(10, 20); 
  matrix.print(p1);  
  matrix.setCursor(textX, 2);                                // Указываем начальную координату вывода текста {textX; 12}
  matrix.print(choose);                                          // Выводим текст
  --textX;                                                    // Сдвигаем текст на 1 пиксель при каждом выполнении цикла
  if(textX < textMin) textX = matrix.width();                 // Если был отображён весь текст, то начинаем его выводить заново
  matrix.swapBuffers(false);
  }
}
